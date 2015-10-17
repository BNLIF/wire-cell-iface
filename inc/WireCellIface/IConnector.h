#ifndef WIRECELL_ICONNECTOR
#define WIRECELL_ICONNECTOR

#include "WireCellIface/IPort.h"
#include "WireCellIface/INode.h"
#include "WireCellUtil/IComponent.h"

#include <string>
#include <memory>
#include <map>

namespace WireCell {

    /** A connector is responsible for forging a connection between an
     * output port and an input port.  A connector instance is
     * associated with the data type that the ports accept.
     */
    class IConnector 
	: public IComponent<IConnector>
    {
    public:
	virtual ~IConnector() {}

	/// Return the name of the type of data passed by the ports this connects.
	virtual std::string port_type_name() const = 0;

	/// Connect a sender to a receiver return false on error.
	virtual bool connect(IPort::pointer sender, IPort::pointer receiver) = 0;

    };


    template<typename PortType>
    class IConnectorT : public IConnector
    {

    public:

	typedef PortType port_type;
	typedef std::shared_ptr<const PortType> pointer;

	virtual ~IConnectorT() {}

	virtual std::string port_type_name() const {
	    return typeid(port_type).name();
	}

	/// Forward to type specific typed version of connect().
	virtual bool connect(IPort::pointer sender, IPort::pointer receiver) {
	    pointer s = std::dynamic_pointer_cast<port_type>(sender);
	    pointer r = std::dynamic_pointer_cast<port_type>(receiver);	    
	    if (!s || !r) { return false; }
	    return connect(s, r);
	}

	/// Convenience method to start from nodes.
	virtual bool connect(INode::pointer sender, INode::pointer receiver) {
	    IPort::pointer s, r;
	    std::string me = port_type_name();
	    for (auto maybe : sender->input_ports()) {
		if (me != maybe->port_type_name()) {
		    break;
		}
		s = maybe;
	    }
	    for (auto maybe : receiver->input_ports()) {
		if (me != maybe->port_type_name()) {
		    break;
		}
		r = maybe;
	    }
	    return connect(s, r);
	}

	/** Subclass must implement. */
	virtual bool connect(pointer sender, pointer receiver) = 0;

    };

}
#endif


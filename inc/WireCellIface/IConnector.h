#ifndef WIRECELL_ICONNECTOR
#define WIRECELL_ICONNECTOR

#include "WireCellIface/IPort.h"
#include "WireCellIface/INode.h"

#include <string>
#include <memory>
#include <map>

namespace WireCell {

    /** A connector is responsible for forging a connection between an
     * output port and an input port.  A connector instance is
     * associated with the data type that the ports accept.
     *
     * See WireCell::IConnectorT
     */
    class IConnector 
    {
    public:
	virtual ~IConnector() {}

	/// Return the name of the type of data passed by the ports this connects.
	virtual std::string port_type_name() const = 0;

	/// Connect a sender to a receiver return false on error.
	virtual bool connect(IPort& sender, IPort& receiver) = 0;

    };

    /** A helper base for implementing an IDataFlowGraph.  
     *
     * Not typically exposed but assists in writing typed connectors
     * for later lookup by a concrete IDataFlowGraph.
     */
    template<typename PortType>
    class IConnectorT : public IConnector
    {

    public:

	typedef PortType port_type;

	virtual ~IConnectorT() {}

	virtual std::string port_type_name() const {
	    return typeid(port_type).name();
	}

	/// Forward to type specific typed version of connect().
	virtual bool connect(IPort& sender, IPort& receiver) {
	    PortType* s = std::dynamic_pointer_cast<PortType*>(&sender);
	    PortType* r = std::dynamic_pointer_cast<PortType*>(&receiver);	    
	    if (!s || !r) { return false; }
	    return connect(*s, *r);
	}

	/// Convenience method to start from nodes.
	virtual bool connect(INode& sender, INode& receiver) {
	    IPort *s = nullptr, *r = nullptr;
	    std::string me = port_type_name();
	    for (auto maybe : sender.input_ports()) {
		if (me != maybe->port_type_name()) {
		    break;
		}
		s = maybe;
	    }
	    for (auto maybe : receiver.input_ports()) {
		if (me != maybe->port_type_name()) {
		    break;
		}
		r = maybe;
	    }
	    if (!r && !s) { return false; }
	    return connect(*s, *r);
	}

	/** Subclass must implement. */
	virtual bool connect(ISending<PortType>& sender, IReceiving<PortType>& receiver) = 0;

    };

}
#endif


#ifndef WIRECELL_ICONNECTOR
#define WIRECELL_ICONNECTOR

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/ISending.h"
#include "WireCellIface/IReceiving.h"
#include <string>
#include <memory>
#include <map>

namespace WireCell {

    /** Interface to a component that knows how to connect a sender
     * and a receiver.  Most likely one should inhered from the
     * intermediate ConnectorBase.
     */
    class IConnector 
	: public IComponent<IConnector>
	, virtual public IPort
    {
    public:
	virtual ~IConnector() {}
	virtual bool connect(ISending::pointer sender, IReceiving::pointer receiver) = 0;

    };


    class ConnectorBase : public IConnector {
	static std::map<std::string, IConnector::pointer> s_connectors;
    public:
	virtual ~ConnectorBase() {}
	
	typedef void port_type;

	/** Knowing the TYPE of the port one can get the connector
	 * like:
	 *
	 * ```
	 * IConnector* con = ConnectorBase::lookup(typeid(TYPE).name());
	 * ```
	 */
	static IConnector::pointer lookup(const std::string& name) {
	    auto maybe = s_connectors.find(name);
	    if (maybe == s_connectors.end()) {
		return nullptr;
	    }
	    return maybe->second;
	}
	
	/** This must be called on each concrete connector if lookup()
	 * is to succeed.
	 */
	void declare() {
	    s_connectors[this->port_type_name()] = IConnector::pointer(this);
	}

    };

    IConnector::pointer connector_lookup(const std::string& type_name) {
	return ConnectorBase::lookup(type_name);
    }

    IConnector::pointer connector_lookup(const IPort& port) {
	return ConnectorBase::lookup(port.port_type_name());
    }

    template<typename PortType>
    class Connector
	: public ConnectorBase
	, public IPortT<PortType>
    {
    public:
	typedef ISendingT<PortType> sending_type;
	typedef typename sending_type::pointer sending_pointer;
	typedef IReceivingT<PortType> receiving_type;
	typedef typename receiving_type::pointer receiving_pointer;

	Connector() {
	    declare();
	}
	virtual ~Connector() {}

	/** Intercept base class `connect()` to call typed `connect()`.
	 */
	virtual bool connect(ISending::pointer sender, IReceiving::pointer receiver) {
	    sending_pointer s = std::dynamic_pointer_cast<sending_type>(sender);
	    receiving_pointer r = std::dynamic_pointer_cast<receiving_type>(receiver);
	    if (!s || !r) { return false; }
	    return connect(s, r);
	}

	/** Subclass must implement.
	 */
	virtual bool connect(sending_pointer& sender, receiving_pointer& receiver) = 0;

    };

}
#endif


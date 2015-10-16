#ifndef WIRECELL_IRECEIVING
#define WIRECELL_IRECEIVING

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IPort.h"
#include <string>

namespace WireCell {

    class IReceiving
	: public IComponent<IReceiving>
	, virtual public IPort
    {
    public:
	virtual ~IReceiving() {}
    };

    /** A DFP base for any node that accepts input of a certain type.
     */
    template<typename PortType>
    class IReceivingT :  virtual public IReceiving, public IPortT<PortType>
    {
    public:
	virtual ~IReceivingT() {}

	typedef IReceivingT<PortType> this_type;
	typedef std::shared_ptr< this_type > pointer;
	typedef typename IPortT<PortType>::port_pointer port_pointer;

	/// Accept a data object for input.  Return false if unable to
	/// accept.
	virtual bool insert(const port_pointer& in) = 0;
    };

}

#endif

#ifndef WIRECELL_ISENDING
#define WIRECELL_ISENDING

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IPort.h"
#include <string>

namespace WireCell {

    class ISending
	: public IComponent<ISending>
	, virtual public IPort
    {
    public:
	virtual ~ISending() {}
    };


    /** A DFP base for any node that provides output of a certain type.
     */
    template<typename PortType>
    class ISendingT : virtual public ISending , public IPortT<PortType>
    {
    public:
	virtual ~ISendingT() {}

	typedef ISendingT<PortType> this_type;
	typedef std::shared_ptr< this_type > pointer;
	typedef typename IPortT<PortType>::port_pointer port_pointer;

	/// Extract one output data object.  Return true if "out" was
	/// set successfully.
	virtual bool extract(port_pointer& out) = 0;
	
    };

}

#endif

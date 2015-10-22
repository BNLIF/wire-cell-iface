#ifndef WIRECELLIFACE_IWIRESOURCE
#define WIRECELLIFACE_IWIRESOURCE

#include "WireCellIface/ISending.h"
#include "WireCellIface/IWire.h"

#include "WireCellUtil/IComponent.h"

namespace WireCell {

    /** Return a vector of wires.
     */
    class IWireSource
	: public IComponent<IWireSource>
	, public ISending<IWire::vector>
    {
    public:
	virtual ~IWireSource() {}

	// supply:
	// virtual bool extract(output_pointer& wires);
    };

}

#endif

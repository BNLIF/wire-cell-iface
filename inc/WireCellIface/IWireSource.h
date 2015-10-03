#ifndef WIRECELLIFACE_IWIRESOURCE
#define WIRECELLIFACE_IWIRESOURCE

#include "WireCellIface/ISource.h"
#include "WireCellIface/IWire.h"

#include "WireCellUtil/IComponent.h"

namespace WireCell {

    /** Return a vector of wires.
     */
    class IWireSource
	: public IComponent<IWireSource>
	, public ISource<IWire::vector>
    {
    public:
	virtual ~IWireSource() {}

	typedef IWire::shared_vector output_type;

	// supply:
	// virtual bool extract(output_type& wires);
    };

}

#endif

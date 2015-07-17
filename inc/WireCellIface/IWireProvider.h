#ifndef WIRECELLIFACE_IWIREPROVIDER
#define WIRECELLIFACE_IWIREPROVIDER

#include "WireCellIface/IWire.h"

namespace WireCell {

    /** Interface which provides access to a definitive source of
     * WireCell::IWire objects. */
    class IWireProvider : virtual public Interface {
    public:
	virtual ~IWireProvider();
	
	/// Provide access to all the provided wires.
	virtual const WireSet& wires() const = 0;
    };

    WIRECELL_DEFINE_INTERFACE(IWireProvider);
}

#endif

#ifndef WIRECELLIFACE_IWIREPROVIDER
#define WIRECELLIFACE_IWIREPROVIDER

#include "WireCellIface/IWire.h"

namespace WireCell {

    /** Interface which provides access to a definitive source of
     * WireCell::IWire objects. */
    class IWireProvider {
    public:
	virtual ~IWireProvider();
	
	/// Provide access to all the provided wires.
	virtual const WireStore& wires() const = 0;
    };

}

#endif

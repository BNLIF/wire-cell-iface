#ifndef WIRECELLIFACE_IWIREPROVIDER
#define WIRECELLIFACE_IWIREPROVIDER

#include "WireCellIface/IWire.h"

namespace WireCell {

    /** WireCell::IWireProvider - interface which provides access to a
     * definitive source of IWire objects. */
    class IWireProvider {
    public:
	virtual ~IWireProvider();
	
	/// Return the all the wires the interface provides
	virtual const WireCell::WireVector& wires() const = 0;
	
    };
}

#endif

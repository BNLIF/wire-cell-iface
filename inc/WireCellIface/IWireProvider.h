#ifndef WIRECELLIFACE_IWIREPROVIDER
#define WIRECELLIFACE_IWIREPROVIDER

#include "WireCellIface/IWire.h"
#include "WireCellIface/IWireIterator.h"

#include <map>			// for pair

namespace WireCell {

    /** Interface which provides access to a definitive source of
     * WireCell::IWire objects. */
    class IWireProvider : virtual public Interface {
    public:

	virtual ~IWireProvider();
	
	/// Return iterator to first wire provided.
	virtual wire_iterator wires_begin() = 0;

	/// Return iterator to one past last wire provided.
	virtual wire_iterator wires_end() = 0;

	/// Convenience method.
	virtual wire_range wires() {
	    wire_range(wires_begin(), wires_end());
	}
    };

    WIRECELL_DEFINE_INTERFACE(IWireProvider);
}

#endif

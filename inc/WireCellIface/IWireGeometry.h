#ifndef WIRECELLIFACE_IWIREGEOMETRY
#define WIRECELLIFACE_IWIREGEOMETRY

#include "WireCellData/GeomWire.h"

namespace WireCell {

    /** WireCell::IWireGeometry - interface providing access to all WireCell::GeomWire */
    class IWireGeometry {
    public:
	virtual ~IWireGeometry();
	
	/// Return the set of all GeomWire objects
	virtual const WireCell::GeomWireSet& get_wires() const = 0;
	
    };
}

#endif

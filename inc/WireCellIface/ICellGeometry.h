#ifndef WIRECELLIFACE_ICELLGEOMETRY
#define WIRECELLIFACE_ICELLGEOMETRY

#include "WireCellData/GeomCell.h"

namespace WireCell {

    /** WireCell::IWireGeometry - interface providing access to all WireCell::GeomCell */
    class ICellGeometry {
    public:
	virtual ~ICellGeometry();
	
	/// Return the set of all GeomCell objects
	virtual const WireCell::GeomCellSet& get_cells() const = 0;
	
    };


}

#endif

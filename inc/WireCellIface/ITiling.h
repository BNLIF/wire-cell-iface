#ifndef WIRECELL_ITILING
#define WIRECELL_ITILING

#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"

namespace WireCell {

    /** Interface class for the heart of Wire Cell.  
     *
     * It provides information about the relationships between wires
     * and cells and between cells.
     */

    class ITiling : virtual public Interface {
    public:
	
	virtual ~ITiling() {}

	/// Return a sequence of wires which are associated with the
	/// given cell.
	virtual wire_range wires(const ICell& cell) const = 0;
	
	/// Return a sequence of cells associated with the given wire.
	virtual cell_range cells(const IWire& wire) const = 0;

	/// Return the cells associated with the collection of wires.
	/// Typically this is expected to be one wire from each plane.
	virtual cell_range cell(const std::vector<const IWire*>& wires) const = 0;

	/// Return collection of nearest neighbor cells.
	virtual cell_range neighbors(const ICell& cell) const = 0;
    };

    WIRECELL_DEFINE_INTERFACE(ITiling);

}

#endif

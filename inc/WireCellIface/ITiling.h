#ifndef WIRECELL_ITILING
#define WIRECELL_ITILING

#include "WireCellUtil/Interface.h"

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

	typedef std::shared_ptr<ITiling> pointer;
	
	virtual ~ITiling() {}

	/// Return a sequence of wires which are associated with the
	/// given cell.
	virtual IWireVector wires(const ICell::pointer& cell) const = 0;
	
	/// Return a sequence of cells associated with the given wire.
	virtual ICellVector cells(const IWire::pointer& wire) const = 0;

	/// Return the cells associated with the collection of wires.
	/// Typically this is expected to be one wire from each plane.
	/// No association results in an empty collection returned.
	virtual ICellVector cell(const IWireVector& wires) const = 0;

	/// Return collection of nearest neighbor cells.
	virtual ICellVector neighbors(const ICell::pointer& cell) const = 0;
    };

}

#endif

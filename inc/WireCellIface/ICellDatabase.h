#ifndef WIRECELL_ICELLDATABASE_H
#define WIRECELL_ICELLDATABASE_H

#include "WireCellIface/ICell.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** Interface class for providing various relational queries a
     * collection of WireCell::ICell objects.
     */

    class ICellDatabase {
    public:

	virtual ~ICellDatabase();

	/// Load the underling cell data.
	virtual void load(const WireCell::CellSet& cells) = 0;

	/// Return collection of wires which are associated with the
	/// given cell.
	virtual WireVector wires(Cell cell) const = 0;
	
	/// Return collection of cells associated with the given wire.
	virtual CellVector cells(Wire wire) const = 0;

	/// Return the one cell associated with the collection of
	/// wires or NULL.
	virtual Cell cell(const WireVector& wires) const = 0;

	/// Return collection of nearest neighbor cells.
	virtual CellVector neighbors(Cell cell) const = 0;
    };

}

#endif

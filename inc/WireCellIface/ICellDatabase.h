#ifndef WIRECELL_ICELLDATABASE_H
#define WIRECELL_ICELLDATABASE_H

#include "WireCellIface/ICell.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** WireCell::ICellDatabase - interface class for providing
     * various relational queries on cells.
     */

    class ICellDatabase {
    public:

	virtual ~ICellDatabase();

	/// Load the underling cell data.
	virtual void load(const WireCell::CellVector& cells) = 0;

	/// Return collection of wires which are associated with the
	/// given cell.
	virtual WireVector wires(const ICell& cell) const = 0;
	
	/// Return collection of cells associated with the given wire.
	virtual CellVector cells(const IWire& wire) const = 0;

	/// Return the one cell associated with the collection of
	/// wires or NULL.
	virtual const ICell* cell(const WireVector& wires) const = 0;

	/// Return collection of nearest neighbor cells.
	virtual const CellVector neighbors(const ICell& cell) const = 0;
    };

}

#endif

#ifndef WIRECELL_ICELLDATABASE_H
#define WIRECELL_ICELLDATABASE_H

#include "WireCellIface/ICell.h"
#include "WireCellIface/IWire.h"
#include "WireCellIface/ICellIterator.h"
#include "WireCellIface/IWireIterator.h"

namespace WireCell {

    /** Interface class for providing various relational queries a
     * collection of WireCell::ICell objects.
     */

    class ICellDatabase : virtual public Interface {
    public:

	virtual ~ICellDatabase();

	/// Load the underling cell data.
	virtual void load(cell_range cells) = 0;

	/// Return collection of wires which are associated with the
	/// given cell.
	virtual wire_range wires(Cell cell) const = 0;
	
	/// Return collection of cells associated with the given wire.
	virtual cell_range cells(Wire wire) const = 0;

	/// Return the one cell associated with the collection of
	/// wires or NULL.
	virtual Cell cell(wire_range wires) const = 0;

	/// Return collection of nearest neighbor cells.
	virtual cell_range neighbors(Cell cell) const = 0;
    };

    WIRECELL_DEFINE_INTERFACE(ICellDatabase);

}

#endif

#ifndef WIRECELL_ICELLSUMMARY
#define  WIRECELL_ICELLSUMMARY

#include "WireCellIface/ICell.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** A cell summary database on cells.
     */
    class ICellSummary : public IData<ICellSummary>
    {
    public:
	
	virtual ~ICellSummary() {}

	/// Return a sequence of wires which are associated with the
	/// given cell.
	virtual IWire::vector wires(ICell::pointer cell) const = 0;
	
	/// Return a sequence of cells associated with the given wire.
	virtual ICell::vector cells(IWire::pointer wire) const = 0;

	/// Return the cells associated with the collection of wires.
	/// Typically this is expected to be one wire from each plane.
	/// No association results in an empty collection returned.
	virtual ICell::pointer cell(const IWire::vector& wires) const = 0;

	/// Return collection of nearest neighbor cells.
	virtual ICell::vector neighbors(ICell::pointer cell) const = 0;
    };
}
#endif

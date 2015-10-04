#ifndef WIRECELLIFACE_CELL_H
#define WIRECELLIFACE_CELL_H

#include "WireCellUtil/Point.h"
#include "WireCellIface/IWire.h"

#include <set>
#include <map>
#include <vector>
#include <memory>

namespace WireCell {

    /// Interface to information about a cell.
    class ICell : public IData<ICell> {
    public:

	virtual ~ICell();

        /// A globally unique ID number (negative is illegal)
        virtual int ident() const = 0;

        /// The cross sectional area of cell parallel to wire plane in [length^2] 
        virtual double area() const = 0;

        /// A representative center of the cell.
        virtual WireCell::Point center() const = 0;

        /// Return a vector of corner points guaranteed to be in order
        /// going around the cell border.
        virtual WireCell::PointVector corners() const = 0;

	/// Return a vector of wires which are associated with this
	/// cell.  The exact association depends on the algorithm
	/// followed to produce the cells.  Most typical is that the
	/// vector will hold one wire from each plane which closely
	/// intersects the cell boundary.  In general, the content and
	/// ordering is not specified.
	virtual WireCell::IWire::vector wires() const = 0;

    };

}
#endif

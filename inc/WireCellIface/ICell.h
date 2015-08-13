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

    };


    /// An abstract base class for anything that can sink a sequence
    /// of cells.
    typedef ISink<ICell> ICellSink;


    /** An abstract base class for a sequence of cells.
     *
     * This could simply be a typedef but it is convenient to provide
     * different names for iterators and begin()/end() to facilitate
     * any subclassing of both IWireSequence and ICellSequence.  If
     * you don't want this cruft, just inherit directly from
     * ISequence<ICell>.
     */
    class ICellSequence : virtual public ISequence<ICell> {
    public:
	typedef std::shared_ptr<ICellSequence> pointer;

	typedef ICell::base_iterator	cell_base_iterator;
	typedef ICell::iterator		cell_iterator;
	typedef ICell::iterator_range	cell_range;

	/// Actual subclass must implement:
	virtual cell_iterator cells_begin() = 0;
	virtual cell_iterator cells_end() = 0;

	virtual cell_range cells_range() { return cell_range(cells_begin(), cells_end()); }

	virtual cell_iterator begin() { return cells_begin(); };
	virtual cell_iterator end() { return cells_end(); };

    };
}

#endif

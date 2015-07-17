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
    class ICell {
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

	/// Return a collection of wires that have an association with
	/// this cell.
	//
	// Fixme: this may be a bad idea.  Besides adding data to a
	// very numerous object, the association between a cell and
	// wires is not 100% guaranteed to be unique.  It's also
	// redundant with ICellDatabase::wires()
	virtual WireCell::WireVector wires() const = 0;

    };

    // No use of bare ICells, everybody shares.  Once made they are
    // forever const.  They are accessed by this pointer-like object
    // Cell.  No need for bare pointers nor references.
    typedef std::shared_ptr<const ICell> Cell;

    /// Compare two cells by their ident.
    struct CellIdentCompare {
	bool operator() (Cell a, Cell b) const {
	    return a->ident() < b->ident();
	}
    };

    /// A a set of cells.
    typedef std::set<Cell, CellIdentCompare> CellSet;

    /// A vector of non-owning pointers to cells.
    typedef std::vector<Cell> CellVector;

    /// A pair of cells associated in some way
    typedef std::pair<Cell, Cell> CellPair;

    /// A mapping between cell and a floating point value
    typedef std::map<Cell, float> CellValueMap; 

    /// A mapping between cell and an integer point value
    typedef std::map<Cell, int> CellIndexMap;
	
}

/// Compare two cells for equality
bool operator==(WireCell::Cell lhs, WireCell::Cell rhs);

/// Compare two cells for lessthan
bool operator<(WireCell::Cell lhs, WireCell::Cell rhs);


std::ostream & operator<<(std::ostream &os, WireCell::Cell cell);


#endif

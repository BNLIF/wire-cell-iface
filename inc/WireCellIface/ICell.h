#ifndef WIRECELLIFACE_CELL_H
#define WIRECELLIFACE_CELL_H

#include "WireCellUtil/Point.h"

#include <set>
#include <map>
#include <vector>

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

    };

    /// Compare two cells by their ident.
    struct CellIdentCompare {
	bool operator() (const ICell* a, const ICell* b) const {
	    return a->ident() < b->ident();
	}
    };

    /// A an owning store for an associated collection of cells.
    typedef std::set<ICell*, CellIdentCompare> CellStore;

    /// A vector of non-owning pointers to cells.
    typedef std::vector<const ICell*> CellVector;

    /// A set of non-owning pointers to wires, ordered by plane and
    /// index.  Only use this when you really need a std::set.  See
    /// also WireCell::IndexedSet from the WireCellUtil package.
    typedef std::set<const ICell*, CellIdentCompare> CellSet;

    /// A pair of cells associated in some way
    typedef std::pair<const ICell*, const ICell*> CellPair;

    /// A mapping between cell and a floating point value
    typedef std::map<const ICell*, float> CellValueMap; 

    /// A mapping between cell and an integer point value
    typedef std::map<const ICell*, int> CellIndexMap;
	
}

/// Compare two cells for equality
bool operator==(const WireCell::ICell &lhs, const WireCell::ICell &rhs);

/// Compare two cells for lessthan
bool operator<(const WireCell::ICell& lhs, const WireCell::ICell& rhs);


std::ostream & operator<<(std::ostream &os, const WireCell::ICell& cell);
std::ostream & operator<<(std::ostream &os, const WireCell::ICell* cellp);


#endif

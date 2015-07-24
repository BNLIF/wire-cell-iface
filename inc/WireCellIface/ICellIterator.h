#ifndef WIRECELL_ICELLITERATOR
#define WIRECELL_ICELLITERATOR

#include "WireCellUtil/Iterator.h"
#include "WireCellUtil/IteratorBase.h"

#include "WireCellIface/ICell.h"

namespace WireCell {

    /// Used internally as an abstract base for cell iterators from a
    /// provider of iterators.
    typedef IteratorBase<const ICell*> cell_base_iterator;

    /// Facade exposed by value to clients an iterator provider.
    typedef Iterator<const ICell*> cell_iterator;

    /// A begin/end pair of iterators.
    typedef std::pair<cell_iterator, cell_iterator> cell_range;


}

#endif

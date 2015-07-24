#ifndef WIRECELL_IWIREITERATOR
#define WIRECELL_IWIREITERATOR

#include "WireCellUtil/Iterator.h"
#include "WireCellUtil/IteratorBase.h"

#include "WireCellIface/IWire.h"

namespace WireCell {

    /// Used internally as an abstract base for wire iterators from a
    /// provider of iterators.
    typedef IteratorBase<const IWire*> wire_base_iterator;

    /// Facade exposed by value to clients an iterator provider.
    typedef Iterator<const IWire*> wire_iterator;

    /// A begin/end pair of iterators.
    typedef std::pair<wire_iterator, wire_iterator> wire_range;


}

#endif

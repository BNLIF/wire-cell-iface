#ifndef WIRECELL_IDATA
#define WIRECELL_IDATA

#include "WireCellUtil/Iterator.h"
#include "WireCellUtil/IteratorBase.h"

#include <boost/range/iterator_range.hpp>
#include <memory>		// std::shared_ptr

namespace WireCell {
    template<class Type>
    class IData {		// note: NOT a WireCell::Interface
    public:

	typedef Type value_type;

	/// Never expose the basic pointer-to-object, but rather only
	/// through shared, const pointers.
	typedef std::shared_ptr<const Type> pointer;

	/// Abstract base iterator
	typedef IteratorBase<pointer> base_iterator;

	/// The facade-iterator which wraps an instance of derived abstract iterator.
	typedef Iterator<pointer> iterator;

	/// A range of iterators.
	typedef boost::iterator_range<iterator> iterator_range;


    };
}

// http://antonym.org/2014/02/c-plus-plus-11-range-based-for-loops.html
// http://stackoverflow.com/questions/8542591/c11-reverse-range-based-for-loop


#endif
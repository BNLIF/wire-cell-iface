#ifndef WIRECELL_IDATA
#define WIRECELL_IDATA

#include "WireCellUtil/Iterator.h"
#include <boost/range/iterator_range.hpp>
#include <memory>		// std::shared_ptr

namespace WireCell {
    template<class Type>
    class IData {
    public:
	typedef std::shared_ptr<Type> ptr;
	typedef std::shared_ptr<const Type> const_ptr;

	typedef WireCell::Iterator<Type> iterator;
	typedef WireCell::Iterator<const Type> const_iterator;

	typedef boost::iterator_range<iterator> range;
	typedef boost::iterator_range<const_iterator> const_range;

	typedef WireCell::Iterator<ptr> ptr_iterator;
	typedef WireCell::Iterator<const_ptr> const_ptr_iterator;

	typedef boost::iterator_range<ptr_iterator> ptr_range;
	typedef boost::iterator_range<const_ptr_iterator> const_ptr_range;

	// use boost::make_iterator_range(beg,end) to make ranges


    };
}

// http://antonym.org/2014/02/c-plus-plus-11-range-based-for-loops.html
// http://stackoverflow.com/questions/8542591/c11-reverse-range-based-for-loop


#endif

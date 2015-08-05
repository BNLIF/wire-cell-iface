#ifndef WIRECELL_ISINK
#define WIRECELL_ISINK

#include "WireCellUtil/Interface.h"
#include "WireCellIface/ISequence.h"

namespace WireCell {

    /** Abstract base class interface for a class which can sink a
     * range of data.
     */
    template<class IDataClass>
    class ISink : virtual public Interface {
    public:
	typedef std::shared_ptr< ISink<IDataClass> > pointer;
	typedef typename IDataClass::iterator_range iterator_range;

	/// Accept a const iterator range of data.
	virtual void sink(const iterator_range& range) = 0;


	virtual ~ISink() {};
    };
    
}



#endif

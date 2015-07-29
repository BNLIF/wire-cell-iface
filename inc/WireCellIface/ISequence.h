#ifndef WIRECELL_ISEQUENCE
#define WIRECELL_ISEQUENCE

#include "WireCellUtil/Interface.h"
#include "WireCellUtil/Iterator.h"
#include "WireCellUtil/IteratorBase.h"

#include <map> 			// for std::pair
#include <memory> 		// for std::shared_ptr

// namespace WireCell {

//     template <class Type>
//     class ISequence : virtual public Interface {
//     public:
// 	virtual ~ISequence() {};

// 	virtual Iterator<const Type*> begin() const = 0;
// 	virtual Iterator<const Type*> end() const = 0;
// 	// virtual std::pair< Iterator<Type> , Iterator<Type> > range() {
// 	//     return std::pair< Iterator<Type> , Iterator<Type> >(begin<Type>(), end<Type>());
// 	// }
//     };

// }

#define WIRECELL_SEQUENCE_ITR(CapName, lowname) \
    namespace WireCell {						\
    typedef IteratorBase<const I##CapName *> lowname##_base_iterator;	\
    typedef Iterator<const I##CapName *> lowname##_iterator;		\
    typedef std::pair< lowname##_iterator, lowname##_iterator > lowname##_range; \
    }

#define WIRECELL_SEQUENCE_ABC(CapName,lowname)				\
    namespace WireCell {						\
	class I##CapName##Sequence : virtual public Interface		\
	{ public:							\
	    virtual ~I##CapName##Sequence() {};				\
	    virtual lowname##_iterator lowname##s_begin() const = 0;	\
	    virtual lowname##_iterator lowname##s_end() const = 0;	\
	    virtual std::size_t lowname##s_size() const = 0;		\
	    virtual lowname##_range lowname##s() const { return lowname##_range(lowname##s_begin(), lowname##s_end()); } \
	};								\
	typedef std::shared_ptr<I##CapName##Sequence> I##CapName##SequencePtr;	\
    }



#define WIRECELL_SEQUENCE_SINK(CapName,lowname)				\
    namespace WireCell {						\
	class I##CapName##Sink : virtual public Interface		\
	{ public:							\
	    virtual ~I##CapName##Sink() {};				\
	    virtual void sink(lowname##_iterator begin, lowname##_iterator end) = 0; \
	    virtual void sink(lowname##_range lowname##s) { sink(lowname##s.first, lowname##s.second); } \
	};								\
	typedef std::shared_ptr<I##CapName##Sink> I##CapName##SinkPtr;	\
    }

#endif

#ifndef WIRECELL_ISOURCE
#define WIRECELL_ISOURCE

#include "WireCellUtil/Interface.h"



#define WIRECELL_SOURCE_ABC(CapName,lowname)				\
    namespace WireCell {						\
	class I##CapName##Source : virtual public Interface		\
	{ public:							\
	    virtual ~I##CapName##Source() {};				\
	    virtual I##CapName :: const_ptr lowname##_gen() = 0;	\
	};								\
    }


#endif

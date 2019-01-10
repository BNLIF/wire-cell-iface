#ifndef WIRECELL_ISTRIP
#define WIRECELL_ISTRIP

#include "WireCellIface/IData.h"
#include "WireCellIface/IChannel.h"
#include "WireCellUtil/Point.h"
#include "WireCellUtil/Units.h"

#include <vector>

namespace WireCell {

    /** An interface to information about a "strip" of channels.  
     *
     * A strip is an ordered, "contiguous" set of channels.
     *
     * Order is application dependent but typically (and why it is
     * named as such) a strip will contain channels in the same plane
     * which are in IChannel "index" ordering (aka, "wire attachement
     * point" order).  Likewise, "contiguous" is typically defined in
     * terms of IChannel "index".
     */
    class IStrip : public IData<IStrip> {
    public:
	
	virtual ~IStrip() ;

        typedef float value_t;

        // A sample is a channels value in the time slice.
	typedef std::pair<IChannel::pointer, value_t> pair_t;
        typedef std::vector<pair_t> vector_t;

        // An identifier.
        virtual int ident() const = 0; 

        // the contiguous, ordered, per channel values.
        virtual vector_t values() const = 0;
    };


}

#endif

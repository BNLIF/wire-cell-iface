#ifndef WIRECELLIFACE_ISLICE
#define WIRECELLIFACE_ISLICE

#include "WireCellIface/IData.h"
#include "WireCellIface/ISink.h"
#include "WireCellIface/ISequence.h"


#include <map>

namespace WireCell {

    /** Interface to one time slice of a frame.  
     *
     * A slice provides access to a collection of charge measurements
     * across the various WireCell::ITrace objects that occurred in a
     * particular time slice.
     */
    class ISlice : public IData<ISlice> {
    public:

	typedef std::map<int,float> ChannelCharge;

	virtual ~ISlice();

	/// Return the time bin relative to some absolute time
	/// (typically the start of the frame) that this slice covers.
	virtual int tbin() const = 0;

	/// Return a mapping from channel identity number and the
	/// charge in that channel in this time slice.
	virtual const ChannelCharge& charge() const = 0;

    };

    typedef ISink<ISlice> ISliceSink;
    typedef ISequence<ISlice> ISliceSequence;
}




#endif

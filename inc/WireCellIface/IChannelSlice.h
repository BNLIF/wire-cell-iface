#ifndef WIRECELLIFACE_ICHANNELSLICE
#define WIRECELLIFACE_ICHANNELSLICE

#include "WireCellIface/IData.h"
#include "WireCellIface/ISink.h"
#include "WireCellIface/ISequence.h"


#include <map>

namespace WireCell {

    /** Interface to one time slice across channels.
     *
     * A channel slice provides access to a collection of charge
     * measurements across the channels at a particular time.
     */
    class IChannelSlice : public IData<IChannelSlice> {
    public:

	typedef std::map<int,float> ChannelCharge;

	virtual ~IChannelSlice() {}

	/// Return the absolute time to which this slice corresponds.
	virtual double time() const = 0;

	/// Return a mapping from channel identity number and the
	/// charge in that channel in this time slice.
	virtual const ChannelCharge& charge() const = 0;

    };

}




#endif

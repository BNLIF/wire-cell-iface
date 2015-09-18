#ifndef WIRECELLIFACE_ICHANNELSLICE
#define WIRECELLIFACE_ICHANNELSLICE

#include "WireCellUtil/Quantity.h" 
#include "WireCellIface/IData.h"
#include "WireCellIface/ISequence.h"

#include <vector>
#include <map>

namespace WireCell {

    // fixme: put this someplace more generic.
    /// A mapping from channel number to charge, with possible uncertainty.
    typedef std::map<int,Quantity> ChannelCharge;


    /** Interface to one time slice across channels.
     *
     * A channel slice provides access to a collection of charge
     * measurements across the channels at a particular time.
     */
    class IChannelSlice : public IData<IChannelSlice> {
    public:

	virtual ~IChannelSlice() {}

	/// Return the absolute time to which this slice corresponds.
	virtual double time() const = 0;

	/// Return a mapping from channel identity number and the
	/// charge in that channel in this time slice.
	virtual ChannelCharge charge() const = 0;

    };

    typedef std::vector<IChannelSlice::pointer> IChannelSliceVector;
}




#endif

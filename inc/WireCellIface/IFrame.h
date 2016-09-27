#ifndef WIRECELLIFACE_IFRAME
#define WIRECELLIFACE_IFRAME

#include "WireCellIface/ITrace.h"

namespace WireCell {

    /** Interface to a sequence of traces.
     *
     * The charge is organized either in time-major or channel-major.
     *
     * traces: time-major, consecutive charge values in a channel
     *
     * slices: channel-major, charge on channels for a given time slice.
     * 
     */
    class IFrame : public IData<IFrame> {

    public:
	virtual ~IFrame() {};
	
	/// (channel, first tick bin, one past last tick bin)
	typedef std::tuple<int, int, int> channel_tick_range_t;
	typedef std::vector<channel_tick_range_t> channel_tick_ranges;

	/// A set of channel masks with associated value and interpretation
	struct ChannelMasking {

	    /// The label may be used to interpret semantic usage of
	    /// this set of channel masks
	    std::string label;	

	    /// The value applies to all channel masks in this set
	    double value;

	    /// The associated channel domains;
	    channel_tick_ranges masks;
	    
	    ChannelMasking(const std::string& l="", double v=0.0,
			   channel_tick_ranges ctr=channel_tick_ranges())
		: label(l), value(v), masks(ctr) { }
	};
	typedef std::vector<ChannelMasking> ChannelMaskings;

	/// Return a vector of traces
	virtual ITrace::shared_vector traces() const = 0;

	/// Return all masks associated with this frame
	virtual ChannelMaskings masks() const {
	    return ChannelMaskings(); // default is empty
	}

	/// Return an identifying number of this frame.
	virtual int ident() const = 0;

	/// Return the start time of the frame in seconds w.r.t. some
	/// global time.
	virtual double time() const = 0;

	/// Return the length of a digitization time bin.
	virtual double tick() const = 0;
    };

}


#endif

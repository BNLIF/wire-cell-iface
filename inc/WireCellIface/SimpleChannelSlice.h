#ifndef WIRECELL_SIMPLECHANNELSLICE
#define WIRECELL_SIMPLECHANNELSLICE

#include "WireCellIface/IChannelSlice.h"


namespace WireCell {

    class SimpleChannelSlice : public IChannelSlice {
	double m_time;
	ChannelCharge m_cc;
    public:

	SimpleChannelSlice(double time, const ChannelCharge& cc)
	    : m_time(time), m_cc(cc) {}
	virtual ~SimpleChannelSlice() {}

	/// Return the absolute time to which this slice corresponds.
	virtual double time() const { return m_time; }

	/// Return a mapping from channel identity number and the
	/// charge in that channel in this time slice.
	virtual ChannelCharge charge() const { return m_cc; }
    };

}

#endif


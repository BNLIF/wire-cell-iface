#ifndef WIRECELLIFACE_ITRACE
#define WIRECELLIFACE_ITRACE

#include "WireCellIface/IData.h"
#include "WireCellIface/ISink.h"
#include "WireCellIface/ISequence.h"

#include <vector>

namespace WireCell {

    /** Interface to charge vs time waveform signal on a channel.
     *
     *	A trace is an ordered sequence of charge measurements in
     *	contiguous time bins.  
     */
    class ITrace : public IData<ITrace>{
    public:
	/// Sequential collection of charge.
	typedef std::vector<float> ChargeSequence;

	virtual ~ITrace() {};

	/// Return the identifier number for the channel on which this
	/// trace was recorded.
	virtual int channel() const = 0;

	/// Return the time bin relative to some absolute time
	/// (typically the start of the frame) at which the first
	/// ADC/charge in the trace was digitized (leading bin edge).
	virtual int tbin() const = 0;

	/// Return the contiguous adc/charge measurements on the
	/// channel starting at tbin.
	virtual const ChargeSequence& charge() const = 0;
    };

    typedef std::vector<ITrace::pointer> ITraceVector;

    /// Something which takes traces.
    typedef ISink<ITrace> ITraceSink;

    /// A sequence of traces (aka a "frame").
    typedef ISequence<ITrace> ITraceSequence;

}


#endif

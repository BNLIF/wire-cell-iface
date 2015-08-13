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
    class IFrame : public ITraceSequence {

    public:
	typedef std::shared_ptr<IFrame> pointer;

	virtual ~IFrame() {};
	
	/// Return an identifying number of this frame.
	virtual int ident() const = 0;

	/// Return the start time of the frame in seconds w.r.t. some
	/// global time.
	virtual double time() const = 0;
    };

    /// An abstract base class for anything that can sink a sequence
    /// of frames.
    typedef ISink<IFrame> IFrameSink;

}


#endif

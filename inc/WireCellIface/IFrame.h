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
	
	/// Return a vector of traces
	virtual ITrace::shared_vector traces() const = 0;

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

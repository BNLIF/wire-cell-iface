#ifndef WIRECELLIFACE_IFRAME
#define WIRECELLIFACE_IFRAME

#include "WireCellIface/ITrace.h"
#include "WireCellIface/IWirePlane.h"
#include "WireCellIface/WirePlaneId.h"
#include "WireCellUtil/Waveform.h"

namespace WireCell {

    /** Interface to a sequence of traces.
     * 
     */
    class IFrame : public IData<IFrame> {

    public:
	virtual ~IFrame() {};
	
	/// Return a vector of traces
	virtual ITrace::shared_vector traces() const = 0;

	/// Return all masks associated with this frame
        // fixme: this should be its own interface
	virtual Waveform::ChannelMaskMap masks() const {
	    return Waveform::ChannelMaskMap(); // default is empty
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

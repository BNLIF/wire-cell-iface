#ifndef WIRECELLIFACE_IFRAME
#define WIRECELLIFACE_IFRAME

#include "WireCellIface/ITrace.h"
#include "WireCellIface/ISliceProvider.h"

namespace WireCell {

    /** Interface to the digitized charge as functions of the channels
     * and the time over some time frame.
     * 
     * The frame spans a  period which is typically taken
     * to be one detector readout window, (sometimes familiarly but
     * confusingly called an "event").
     *
     * The charge is organized either in time-major or channel-major.
     *
     * traces: time-major, consecutive charge values in a channel
     *
     * slices: channel-major, charge on channels for a given time slice.
     * 
     */
    class IFrame {

    public:
	virtual ~IFrame();
	
	/// Return an identifying number of this frame.
	virtual int ident() const = 0;

	/// Return all traces in the frame
	virtual const TraceCollection& traces() const = 0;

	/// Return the slices in this frame
	virtual ISliceProvider& slices() = 0;
	virtual const ISliceProvider& slices() const = 0;

    };

}

#endif

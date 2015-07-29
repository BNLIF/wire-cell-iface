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
	virtual ~IFrame();
	
	/// Return an identifying number of this frame.
	virtual int ident() const = 0;

    };

}

WIRECELL_SEQUENCE_ITR(Frame,frame);
WIRECELL_SEQUENCE_ABC(Frame,frame);
WIRECELL_SEQUENCE_SINK(Frame,frame);

#endif

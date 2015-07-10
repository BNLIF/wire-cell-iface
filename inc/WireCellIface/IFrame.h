#ifndef WIRECELLIFACE_IFRAME
#define WIRECELLIFACE_IFRAME

namespace WireCell {

    /// IFrame - interface to a collection of traces that span some
    /// contemporaneous time period.  This period is typically taken
    /// to be one detector readout window, (sometimes familiarly but
    /// confusingly called an "event").
    class IFrame {

    public:
	virtual ~IFrame();
	
	/// Return an identifying number of this frame.
	virtual int ident() const = 0;

	/// Return all traces in the frame
	virtual const TraceCollection& traces() const = 0;
    };

}

#endif

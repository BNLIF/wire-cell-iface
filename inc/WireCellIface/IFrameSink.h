#ifndef WIRECELL_IFRAMESINK
#define WIRECELL_IFRAMESINK

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/ISink.h"
#include "WireCellIface/IFrame.h"

namespace WireCell {

    /** A frame sink is something that generates IFrames.
     */
    class IFrameSink
	: public IComponent<IFrameSink>
	, public ISink<IFrame>
    {
    public:
	virtual ~IFrameSink() {}

	// supply:
	// virtual bool extract(IFrame::pointer& frame);

    };


}

#endif

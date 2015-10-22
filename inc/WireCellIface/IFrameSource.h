#ifndef WIRECELL_IFRAMESOURCE
#define WIRECELL_IFRAMESOURCE

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/ISending.h"
#include "WireCellIface/IFrame.h"

namespace WireCell {

    /** A frame source is something that generates IFrames.
     */
    class IFrameSource
	: public IComponent<IFrameSource>
	, public ISending<IFrame>
    {
    public:
	virtual ~IFrameSource() {}

	// supply:
	// virtual bool extract(IFrame::pointer& frame);

    };


}

#endif

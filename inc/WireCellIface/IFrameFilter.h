#ifndef WIRECELL_IFRAMEFILTER
#define WIRECELL_IFRAMEFILTER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IFunctionNode.h"
#include "WireCellIface/IFrame.h"

namespace WireCell {

    /** A frame filter is something that provides one IFrame for every
     * IFrame it is given.
     */
    class IFrameFilter : public IFunctionNode<IFrame,IFrame>
    {
    public:
	virtual ~IFrameFilter() {}

	// supply:
	// virtual bool operator()(const input_pointer& in, output_pointer& out);

    };


}

#endif

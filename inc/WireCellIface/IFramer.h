#ifndef WIRECELL_IFRAMER
#define WIRECELL_IFRAMER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IProcessor.h" //fixme: maybe this should go into util.
#include "WireCellIface/IFrame.h"
#include "WireCellIface/IChannelSlice.h"

namespace WireCell {

    class IFramer
	: public IComponent<IFramer>
	, public IProcessor
	, public ISink<IChannelSlice::pointer>
	, public ISource<IFrame::pointer>
    {
    public:
	~IFramer() {}
    };
}

#endif

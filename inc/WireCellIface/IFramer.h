#ifndef WIRECELL_IFRAMER
#define WIRECELL_IFRAMER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IConverter.h"
#include "WireCellIface/IFrame.h"
#include "WireCellIface/IChannelSlice.h"

namespace WireCell {

    class IFramer
	: public IComponent<IFramer>
	, public IConverter<IChannelSlice::pointer, IFrame::pointer>
    {
    public:
	virtual ~IFramer() {}

    };
}

#endif

#ifndef WIRECELL_IFRAMER
#define WIRECELL_IFRAMER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IConverter.h"
#include "WireCellIface/IFrame.h"
#include "WireCellIface/IChannelSlice.h"

namespace WireCell {

    /** A framer is something that builds a block of digitized data
     * over some period of time.
     *
     * A framer is the inverse of a WireCell::ISlicer.
     *
     */
    class IFramer
	: public IComponent<IFramer>
	, public IConverter<IChannelSlice::pointer, IFrame::pointer>
    {
    public:
	virtual ~IFramer() {}

    };
}

#endif

#ifndef WIRECELL_IFRAMER
#define WIRECELL_IFRAMER

#include "WireCellIface/IBufferNode.h"
#include "WireCellIface/IFrame.h"
#include "WireCellIface/IChannelSlice.h"

namespace WireCell {

    /** A framer is something that builds a block of digitized data
     * that spans some period of time from a number of channel slices.
     *
     * A framer is the inverse of a WireCell::ISlicer.
     *
     */
    class IFramer : public IBufferNode<IChannelSlice, IFrame>
    {
    public:
	virtual ~IFramer() {}

    };
}

#endif

#ifndef WIRECELL_IDIGISLICER
#define WIRECELL_IDIGISLICER

#include "WireCellIface/IJoinNode.h"
#include "WireCellIface/IChannelSlice.h"
#include "WireCellIface/IPlaneSlice.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** A digislicer is a function node which produces one channel slice from
     * an input vector one plane slice per wire plane.
     */
    class IDigislicer : public IJoinNode<std::tuple<IPlaneSlice::vector, IWire::vector>, IChannelSlice>
    {
    public:
	virtual ~IDigislicer() {}

	virtual std::string signature() {
	   return typeid(IDigislicer).name();
	}
    };

}

#endif

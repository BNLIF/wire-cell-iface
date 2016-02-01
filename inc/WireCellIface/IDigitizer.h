#ifndef WIRECELL_IDIGITIZER
#define WIRECELL_IDIGITIZER

#include "WireCellIface/IJoinNode.h"
#include "WireCellIface/IChannelSlice.h"
#include "WireCellIface/IPlaneSlice.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** A digitizer is a function node which produces one channel slice from
     * an input vector one plane slice per wire plane.
     */
    class IDigitizer : public IJoinNode<std::tuple<IPlaneSlice::vector, IWire::vector>, IChannelSlice>
    {
    public:
	virtual ~IDigitizer() {}

	virtual std::string signature() {
	   return typeid(IDigitizer).name();
	}
    };

}

#endif

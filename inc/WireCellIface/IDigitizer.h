#ifndef WIRECELL_IDIGITIZER
#define WIRECELL_IDIGITIZER

#include "WireCellUtil/IComponent.h"

#include "WireCellIface/IProcessor.h"
#include "WireCellIface/IChannelSlice.h"
#include "WireCellIface/IPlaneSlice.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** A digitizer is a processor which produces channel slices from
     * an input vector of place slices, one per plane given the input
     * wire vector.
     */
    class IDigitizer
	: public IComponent<IDigitizer>
	, public IProcessor
	, public ISink<IWireVector>
	, public ISink<IPlaneSliceVector>
	, public ISource<IChannelSlice::pointer>
    {
    public:
	virtual ~IDigitizer() {}
    };

};

#endif

#ifndef WIRECELL_IDIGITIZER
#define WIRECELL_IDIGITIZER

#include "WireCellUtil/IComponent.h"

#include "WireCellIface/IConverter.h"
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
	, virtual public IConverter<IPlaneSlice::vector, IChannelSlice>
    {
    public:
	virtual ~IDigitizer() {}

	virtual bool set_wires(const IWire::shared_vector& wires) = 0;
    };

}

#endif

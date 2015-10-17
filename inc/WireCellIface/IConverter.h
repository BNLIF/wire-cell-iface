#ifndef WIRECELL_ICONVERTER
#define WIRECELL_ICONVERTER

#include "WireCellIface/ISending.h"
#include "WireCellIface/IReceiving.h"

namespace WireCell {

    /** A converter is a simple function-like processor which takes
     * one type of input stream, converting it to one type of output
     * stream.
     */
    template<typename InputType, typename OutputType>
    class IConverter
	: virtual public IReceivingT<InputType> 
	, virtual public ISendingT<OutputType>
    {
    public:

	typedef std::shared_ptr<const InputType> input_type;
	typedef std::shared_ptr<const OutputType> output_type;

	virtual ~IConverter() {}
    };
}

#endif


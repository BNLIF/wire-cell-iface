#ifndef WIRECELL_ICONVERTER
#define WIRECELL_ICONVERTER

#include "WireCellIface/IBuffering.h"
#include "WireCellIface/ISending.h"
#include "WireCellIface/IReceiving.h"
namespace WireCell {

    /** A converter is a simple function-like processor which takes
     * one type of input stream, converting it to one type of output
     * stream.  See also WireCell::IBuffering.
     */
    template<typename InputType, typename OutputType>
    class IConverter
	: public IReceiving<InputType>, 
	  public ISending<OutputType> {
    public:

	typedef std::shared_ptr<const InputType> input_type;
	typedef std::shared_ptr<const OutputType> output_type;

	virtual ~IConverter() {}

    };


}

#endif


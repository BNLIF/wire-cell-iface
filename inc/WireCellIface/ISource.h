#ifndef WIRECELL_ISOURCE
#define WIRECELL_ISOURCE

#include "WireCellIface/ISending.h"

namespace WireCell {

    /** A source of something 
     */
    template<typename OutputType>
    class ISource
	: virtual public ISending<OutputType>
    {
    public:
	virtual ~ISource() {}

	typedef std::shared_ptr<const OutputType> output_type;
	// supply:
	// virtual bool extract(output_type& out);

    };
}

#endif
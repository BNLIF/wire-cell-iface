#ifndef WIRECELL_ISOURCE
#define WIRECELL_ISOURCE

#include "WireCellIface/ISending.h"

namespace WireCell {

    /** A source of something 
     */
    template<typename Output>
    class ISource : public ISending<Output>
    {
    public:
	virtual ~IFrameSource() {}

	typedef std::shared_ptr<OutputType> output_type;
	// supply:
	// virtual bool extract(output_type& out);

    };
}

#endif

#ifndef WIRECELL_ISINK
#define WIRECELL_ISINK

#include "WireCellIface/IReceiving.h"

namespace WireCell {

    /** A sink of something 
     */
    template<typename InputType>
    class ISink : public IReceiving<InputType>
    {
    public:
	virtual ~ISink() {}

	typedef std::shared_ptr<const InputType> input_type;
	// supply:
	// virtual bool insert(const input_type& in);

    };
}

#endif

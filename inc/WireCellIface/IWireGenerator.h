#ifndef WIRECELLIFACE_IWIREGENERATOR
#define WIRECELLIFACE_IWIREGENERATOR

#include "WireCellIface/IWireParameters.h"

namespace WireCell {

    /** Interface which provides access to a definitive source of
     * WireCell::IWire objects. */
    class IWireGenerator : virtual public Interface {
    public:
	virtual ~IWireGenerator();
	
	/// Generate your wires.
	virtual void generate(const WireCell::IWireParameters& params) = 0;
    };

}

#endif

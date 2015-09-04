#ifndef WIRECELLIFACE_IWIREGENERATOR
#define WIRECELLIFACE_IWIREGENERATOR

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IConverter.h"
#include "WireCellIface/IWireParameters.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** A wire generator takes a set of parameters and generates a
     * vector of wires.
     */
    class IWireGenerator
	: public IComponent<IWireGenerator>
	, public IConverter<IWireParameters::pointer, IWireVector>
    {
    public:

	virtual ~IWireGenerator() {}
	
    };

}

#endif

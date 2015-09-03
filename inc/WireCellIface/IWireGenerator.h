#ifndef WIRECELLIFACE_IWIREGENERATOR
#define WIRECELLIFACE_IWIREGENERATOR

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IProcessor.h"
#include "WireCellIface/IWireParameters.h"
#include "WireCellIface/IWire.h"

namespace WireCell {

    /** A wire generator takes a set of parameters and generates a
     * vector of wires.
     */
    class IWireGenerator
	: public IComponent<IWireGenerator>
	, public ISink<IWireParameters::pointer>
	, public ISource<IWireVector>
    {
    public:

	virtual ~IWireGenerator() {}
	
    };

}

#endif

/** WireCell::IWireGenerator is sort of a special interface in that it
 * denotes some object which will accept a special
 * WireCell:IWireParameters object.
 *
 * The intention is that the object then goes on to generate wires and
 * make them available via the WireCell:IWireSequence interface.
 */
#ifndef WIRECELLIFACE_IWIREGENERATOR
#define WIRECELLIFACE_IWIREGENERATOR

#include "WireCellIface/IWireParameters.h"

namespace WireCell {

    /** Interface which provides access to a definitive source of
     * WireCell::IWire objects. */
    class IWireGenerator : virtual public TypedInterface<IWireGenerator> {
    public:
	//typedef std::shared_ptr<IWireGenerator> pointer;

	virtual ~IWireGenerator() {}
	
	/// Generate your wires.
	virtual void generate(WireCell::IWireParameters::pointer params) = 0;
    };

}

#endif

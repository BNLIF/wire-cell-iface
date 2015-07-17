#ifndef WIRECELLIFACE_IWIREPARAMETERS
#define WIRECELLIFACE_IWIREPARAMETERS

#include "WireCellUtil/Interface.h"
#include "WireCellUtil/Point.h"

namespace WireCell {

    /** Interface by which parameters describing wire planes can be accessed.
     */
    class IWireParameters : virtual public Interface {
    public:
	virtual ~IWireParameters();

	/** Provide access to the rays which were used to define the wires. */
	virtual const Ray& bounds() const = 0;
	virtual const Ray& pitchU() const = 0;
	virtual const Ray& pitchV() const = 0;
	virtual const Ray& pitchW() const = 0;

    };

    WIRECELL_DEFINE_INTERFACE(IWireParameters);
}


#endif

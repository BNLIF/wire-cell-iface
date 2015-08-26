#ifndef WIRECELLIFACE_IPLANESLICE
#define WIRECELLIFACE_IPLANESLICE

#include "WireCellIface/IData.h"
#include "WireCellIface/ISink.h"
#include "WireCellIface/ISequence.h"
#include "WireCellIface/WirePlaneId.h"


#include <map>

namespace WireCell {

    /** Interface to charge measured by wires in a plane at a particular time.
     *
     */
    class IPlaneSlice : public IData<IPlaneSlice> {
    public:

	virtual ~IPlaneSlice() {}

	/// The plane ident
	virtual WirePlaneId planeid() const = 0;


	/// Return the absolute time to which this slice corresponds.
	virtual double time() const = 0;


	/// Return the wire index of the first entry of charge vector.
	virtual int first() const = 0;

	/// Return the vector of charge indexed by wire index + first().
	virtual const std::vector<double>& charge() const = 0;

    };

}




#endif

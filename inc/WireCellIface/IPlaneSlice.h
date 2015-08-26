#ifndef WIRECELLIFACE_IPLANESLICE
#define WIRECELLIFACE_IPLANESLICE

#include "WireCellIface/IData.h"
#include "WireCellIface/ISink.h"
#include "WireCellIface/ISequence.h"
#include "WireCellIface/WirePlaneId.h"


#include <map>
#include <vector>

namespace WireCell {

    /** Interface to charge measured by wires in a plane at a particular time.
     *
     */
    class IPlaneSlice : public IData<IPlaneSlice> {
    public:

	// A mapping of a starting wire index to a run of
	// charge-on-wires starting at that index.
	typedef std::map<int, std::vector<double> > ChargeGrouping;

	virtual ~IPlaneSlice() {}

	/// Where: the plane ID
	virtual WirePlaneId planeid() const = 0;


	/// When: the absolute time to which this slice corresponds.
	virtual double time() const = 0;


	/// What: the charge groupings in the plane slice.
	virtual ChargeGrouping charge_groups() const = 0;
	// fixme: should this return an ISequence of some type?
    };

}




#endif

#ifndef WIRECELLIFACE_IPLANESLICE
#define WIRECELLIFACE_IPLANESLICE

#include "WireCellIface/IData.h"
#include "WireCellIface/ISequence.h"
#include "WireCellIface/WirePlaneId.h"


#include <map>
#include <vector>

namespace WireCell {

    /** Interface to charge measured by wires in one plane at a
     * particular time.
     *
     * This is a simulated (or possibly reconstructed) object.  For a
     * similar object for real data see WireCell::IChannelSlice.
     */
    class IPlaneSlice : public IData<IPlaneSlice> {
    public:

	/// A run of charge measured on contiguous wires starting with
	/// a given wire index.
	typedef std::pair< int, std::vector<double> > WireChargeRun;

	/// A collection of WireChargeRun objects.
	typedef std::vector<WireChargeRun> WireChargeRunVector;

	// fixme: although we can keep individual contributions
	// separate we don't store any back pointers to what made each
	// wire charge run.

	virtual ~IPlaneSlice() {}

	/// Where: the plane ID
	virtual WirePlaneId planeid() const = 0;


	/// When: the absolute time to which this slice corresponds.
	virtual double time() const = 0;


	/// What: return all wire charge runs
	virtual WireChargeRunVector charge_runs() const = 0;

	/// Return a flat vector which is the summing all runs.  If
	/// maxwires is given truncate the vector or pad it out with
	/// zeros to match.
	virtual std::vector<double> flatten() const = 0;

    };

    typedef std::vector<IPlaneSlice::pointer> IPlaneSliceVector;

}




#endif

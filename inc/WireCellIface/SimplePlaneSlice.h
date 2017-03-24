#ifndef WIRECELLIFACE_SIMPLEPLANESLICE
#define WIRECELLIFACE_SIMPLEPLANESLICE

#include "WireCellIface/IPlaneSlice.h"

#include <vector>

namespace WireCell {

    class SimplePlaneSlice : public WireCell::IPlaneSlice {
	WirePlaneId m_wpid;
	double m_time;
	WireChargeRunVector m_wcrv;

    public:
	SimplePlaneSlice(WireCell::WirePlaneId ident, double time,
			 const WireChargeRunVector& wcrv)
	    : m_wpid(ident),
	      m_time(time)
	    , m_wcrv(wcrv) { }

	virtual ~SimplePlaneSlice() {}

	/// Where: the plane ID
	virtual WirePlaneId planeid() const { return m_wpid; }


	/// When: the absolute time to which this slice corresponds.
	virtual double time() const { return m_time; }


	/// What: return all wire charge runs
	virtual WireChargeRunVector charge_runs() const { return m_wcrv; }

	/// Return a flat vector which is the summing all runs.  If
	/// maxwires is given truncate the vector or pad it out with
	/// zeros to match.
	virtual std::vector<double> flatten() const;

    };

}

#endif

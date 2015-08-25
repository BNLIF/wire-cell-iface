#ifndef WIRECELL_IDEPO
#define WIRECELL_IDEPO

#include "WireCellIface/IData.h"
#include "WireCellUtil/Point.h"
#include "WireCellUtil/Units.h"

#include <boost/signals2.hpp>
#include <set>

namespace WireCell {

    /** An interface to information about a deposition of charge.
     */
    class IDepo : public IData<IDepo> {
    public:
	
	virtual ~IDepo() {};

	/// The location of the deposition.
	virtual const Point& pos() const = 0;

	/// The number of seconds from some absolute start time to
	/// when the deposition occur ed.
	virtual double time() const = 0;

	/// The number charge (in units of number of electrons) deposited.
	virtual double charge() const = 0;
	
	/// If the deposition is drifted, this may allow access to the original.
	virtual pointer prior() const = 0;

    };

    typedef std::vector<IDepo::pointer> IDepoVector;

    /// Simple utility to return a vector of depositions formed by
    /// walking the prior() chain.  The vector begins with the most
    /// recent.
    IDepoVector depo_chain(IDepo::pointer recent);

    /// Compare how "far" two depositions are from the origin along
    /// the drift-line (metric: dT + dX/V_drift) given a drift velocity.
    struct IDepoDriftCompare {
	double drift_velocity;
	IDepoDriftCompare(double drift_velocity = 1.6 *units::mm/units::microsecond)
	    : drift_velocity(drift_velocity) {};
	bool operator()(const IDepo::pointer& lhs, const IDepo::pointer& rhs) const {
	    double t1 = lhs->time() + lhs->pos().x()/drift_velocity;
	    double t2 = rhs->time() + rhs->pos().x()/drift_velocity;
	    if (t1 == t2) {
		// make sure there are no ties due to precision!
		return lhs.get() < rhs.get(); 
	    }
	    return t1 < t2;
	}
    };
    typedef std::set<IDepo::pointer, IDepoDriftCompare> DepoTauSortedSet;


}

#endif

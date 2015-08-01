#ifndef WIRECELL_IDEPO
#define WIRECELL_IDEPO

#include "WireCellIface/ISequence.h"

#include "WireCellUtil/Point.h"
#include "WireCellUtil/Units.h"

namespace WireCell {

    class IDepo;
    typedef std::shared_ptr<const IDepo> IDepoPtr;

    /** An interface to information about a deposition of charge.
     */
    class IDepo {
    public:
	virtual ~IDepo() {};

	/// The location of the deposition.
	virtual const Point& pos() const = 0;

	/// The number of seconds from some absolute start time to
	/// when the deposition occur ed.
	virtual double time() const = 0;

	/// The number charge (in units of number of electrons) deposited.
	virtual double charge() const = 0;
	
	/// If the deposition is drifted, this accesses the original.
	virtual IDepoPtr original() const { return 0; }

    };

}


WIRECELL_SEQUENCE_ITR(Depo,depo);
WIRECELL_SEQUENCE_ABC(Depo,depo);
WIRECELL_SEQUENCE_SINK(Depo,depo);

namespace WireCell {

    typedef IteratorBase<IDepoPtr> depoptr_base_iterator;
    typedef Iterator<IDepoPtr> depoptr_iterator;
    typedef std::pair< depoptr_iterator, depoptr_iterator > depoptr_range;

    /// Compare how "far" two depositions are from the origin along
    /// the drift-line (metric: dT + dX/V_drift) given a drift velocity.
    class IDepoPtrDriftCompare {
	double m_drift_velocity;
    public:
	IDepoPtrDriftCompare(double drift_velocity = 1.6 *units::mm/units::microsecond)
	    : m_drift_velocity(drift_velocity) {};
	bool operator()(const IDepoPtr& lhs, const IDepoPtr& rhs) const {
	    double t1 = lhs->time() + lhs->pos().x()/m_drift_velocity;
	    double t2 = rhs->time() + rhs->pos().x()/m_drift_velocity;
	    return t1 < t2;
	}
	double drift_velocity() { return m_drift_velocity; }
    };

}

#endif

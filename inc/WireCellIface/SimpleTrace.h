#ifndef WIRECELL_SIMPLETRACE
#define  WIRECELL_SIMPLETRACE

#include "WireCellIface/ITrace.h"

#include <map>
#include <vector>

namespace WireCell {

    /** This concrete trace is filled by time bin and charge.
     * 
     * It provides the results of the filling such that the ChargeSequence
     * is trivially (exactly) zero suppressed but only at the ends.  Any
     * zeros bounded by non-zero charge are kept.
     */
    class SimpleTrace : public ITrace {
	int m_chid;
	int m_tbin;
	ChargeSequence m_charge;
    public:
	SimpleTrace(int chid, int tbin, const ChargeSequence& charge);

	virtual int channel() const;

	virtual int tbin() const;

	// return vector of charge starting at tbin
	virtual const ChargeSequence& charge() const;
    };

    

}

#endif

#ifndef WIRECELLIFACE_ICELLSLICE
#define WIRECELLIFACE_ICELLSLICE

#include "WireCellUtil/Quantity.h" 
#include "WireCellIface/IData.h"
#include "WireCellIface/ICell.h"

#include <vector>
#include <map>

namespace WireCell {

    /** Interface to one time slice across cells.
     *
     * A cell slice provides access to a collection of cells at a
     * particular time.
     */
    class ICellSlice : public IData<ICellSlice> {
    public:

	virtual ~ICellSlice() {}

	/// Return the absolute time to which this slice corresponds.
	virtual double time() const = 0;

	/// Return a mapping from channel identity number and the
	/// charge in that channel in this time slice.
	virtual ICell::shared_vector cells() const = 0;
    };

    // A set ordered by time
    struct ICellSliceCompareTime {
	bool operator()(const ICellSlice::pointer& lhs, const ICellSlice::pointer& rhs) const {
	    if (lhs->time() == rhs->time()) {
		return lhs.get() < rhs.get(); // break tie with pointer
	    }
	    return lhs->time() < rhs->time();
	}
    };
    typedef std::set<ICellSlice::pointer, ICellSliceCompareTime> ICellSliceSet;

}




#endif

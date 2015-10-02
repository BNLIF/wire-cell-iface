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

    typedef std::vector<ICellSlice::pointer> ICellSliceVector;

}




#endif

/** A blob set holds a collection of blobs which are related through
 * their start time value.  They may thus span multiple time slices.
 *
 * See also ICluster which is like IBlobSet but adds associations.
 */

#ifndef WIRECELL_IBLOBSET
#define WIRECELL_IBLOBSET

#include "WireCellIface/IData.h"
#include "WireCellIface/IBlob.h"
#include "WireCellIface/ISlice.h"

namespace WireCell {

    class IBlobSet : public IData<IBlobSet> {
    public:
	virtual ~IBlobSet() ;

        /// Return some identifier number that is unique to this set.
        virtual int ident() const = 0;

        /// Which face this set belongs.
        virtual int face() const = 0;

        /// The slice from which this set was generated.
        virtual ISlice::pointer slice() const = 0;

        /// Return the blobs in this set.  There is no ordering
        /// requirement.
        virtual IBlob::vector blobs() const = 0;

        /// Return a vector of the underlying IBlob::shape() in order.
        virtual RayGrid::blobs_t shapes() const;

    };
}

#endif

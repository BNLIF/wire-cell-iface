/** A blob set holds a collection of blobs which are related through
 * their start time value.  They may thus span multiple time slices.
 *
 * See also ICluster which is like IBlobSet but adds associations.
 */

#ifndef WIRECELL_IBLOBSET
#define WIRECELL_IBLOBSET

#include "WireCellIface/IData.h"
#include "WireCellIface/IBlob.h"

namespace WireCell {

    class IBlobSet : public IData<IBlobSet> {
    public:
	virtual ~IBlobSet() ;

        /// Return some identifier number that is unique to this set.
        virtual int ident() const = 0;

        /// Return the absolute time - eg, that which an IFrame might provide
        virtual double time() const = 0;

        /// Return the strips in this set.  There is no ordering requirement.
        virtual IBlob::vector blobs() const = 0;

    };
}

#endif

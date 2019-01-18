#ifndef WIRECELL_IBLOBSET
#define WIRECELL_IBLOBSET

#include "WireCellIface/IData.h"

namespace WireCell {

    class IBlobSet : public IData<IBlobSet> {
    public:
	virtual ~IBlobSet() ;

        /// Return some identifier number that is unique to this set.
        virtual int ident() const = 0;

        /// Return the strips in this set.  There is no ordering requirement.
        virtual IBlob::vector blobs() const = 0;
    };
}

#endif

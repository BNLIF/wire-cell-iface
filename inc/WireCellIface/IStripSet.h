#ifndef WIRECELL_ISTRIPSET
#define WIRECELL_ISTRIPSET

#include "WireCellIface/IStrip.h"

namespace WireCell {

    /** An interface to information about a collection of IStrip.
     */
    class IStripSet : public IData<IStripSet> {
    public:
	virtual ~IStripSet() ;

        /// Return some identifier number that is unique to this set.
        virtual int ident() const = 0;

        /// Return the strips in this set.  There is no ordering requirement.
        virtual IStrip::vector strips() const = 0;
    };
}

#endif

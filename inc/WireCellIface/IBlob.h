/** 

    A blob is a region in space which is bounded in the
    drift-transverse directions by wires from two or more planes and
    extruded along the drift direction spanning some time slice.

    It is bound by wire segments thus any ambiguity due to wire
    wrapping is not reflected in the IBlob itself.

    Each limiting pair of wires may reference an IStrip from which
    they were derirved.

 */

#ifndef WIRECELL_IBLOB
#define WIRECELL_IBLOB

#include "WireCellIface/IBlob.h"

#include "WireCellIface/IStrip.h"

namespace WireCell {


    class IBlob : public IData<IBlob> {
    public:

        // Two wires, typically representing a bounding of the blob in one plane.
        typedef std::pair<IWire::pointer, IWire::pointer> wire_pair_t;

        virtual ~IBlob();
        
        // An identifier for this blob.
        virtual int ident() const = 0;
        
        // The associated value, aka "charge".
        virtual float value() = 0;

        // And its uncertainty
        virtual float uncertainty() = 0;

        // The per plane boundary wires of the blob
        virtual wire_pair_t boundary_wires() const = 0;

        // An optional method.  Implementation should override if the
        // blob is constructed from strips and this should return
        // those strips in a vector that aligns with that from
        // boundary_wires().
        virtual IStrip::vector parent_strips() const { return IStrip::vector(); }

        // An optional method.  Implementation should override if the
        // blob is constructed from prior blobs and this should return
        // those blobs.
        virtual IBlob::vector priors() const { return IBlob::vector(); }

    };

}

#endif

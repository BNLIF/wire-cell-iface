/** 

    A blob is a region in 3D "drift space" which is bounded in the
    drift-transverse plane through application of a number of
    "layers".  Each layer consists of a pair of parallel "rays" which
    bound the blob along their mutually transverse "pitch direction".
    Layers may correspond to wire planes or to boundaries of active
    regions of the anode plane face.

    The boundary edges and corners of a blob in the transverse plane
    ared is defined in terms of RayGrid indicies.  These assume some
    mapping to physical coordinates (ie, a RayGrid::Coordinates
    object).  See WCT manual for details.

    The third dimension that a blob spans is that of a time slice
    which is positioned relative to some reference time.  See IBlobSet
    for one way to provide an absolute time.

 */

#ifndef WIRECELL_IBLOB
#define WIRECELL_IBLOB

#include "WireCellIface/IBlob.h"

#include "WireCellUtil/RayGrid.h"

namespace WireCell {


    class IBlob : public IData<IBlob> {
    public:


        virtual ~IBlob();
        
        // An identifier for this blob.
        virtual int ident() const = 0;
        
        // An associated value, aka "charge".
        virtual float value() = 0;

        // And its uncertainty
        virtual float uncertainty() = 0;

        // Return the relative start time of this blob.
        virtual double start() const = 0;

        // Return the time span of this blob
        virtual double span() const = 0;

        // The collection of per layer boundary rays
        typedef std::vector<RayGrid::grid_range_t> edges_t;
        
        virtual edges_t edges() const = 0;

        // The collection of corners represented in terms of a two
        // pairs of layer/grid indices.
        virtual RayGrid::crossings_t corners() const = 0;

    };

}

#endif

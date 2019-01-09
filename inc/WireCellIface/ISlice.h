/** 

A slice represents a collection of scalar values, each associated
with a channel and agregated over a slice of time.

The time span of the slice is given in the WCT system of units.
Typically it is some multiple of sampling ticks, but need not be.

The slice also caries an "ident" number which typically will be
used to indicate an index into some implicit ordered array of other
slices (see ISliceFrame).

Channels are identified by their "ident" number which should be
treated as opaque to the application and in particular is NOT
guaranteed to be an index type number.

*/

#ifndef WIRECELL_ISLICE
#define WIRECELL_ISLICE

#include "WireCellIface/IData.h"

#include <unordered_map>

namespace WireCell {

    class ISlice : public IData<ISlice> {
    public:
        virtual ~ISlice();

        // The type for the value of the per channel metric (aka charge)
        typedef float value_t;

        // The opaque channel identifier.  Do not assume this is an index.
        typedef int channel_ident_t;

        // A sample is a channels value in the time slice.
	typedef std::unordered_map<channel_ident_t, value_t> channel_value_map_t;

        // Return a opaque numerical identifier of this time slice
        // unique in some broader context.
        virtual int ident() const = 0; 

        // Return the start time of this time slice.  
        virtual double start() const = 0;

        // Return the time span of this slice
        virtual double span() const = 0;

        virtual channel_value_map_t values() const = 0;

    };
}

#endif

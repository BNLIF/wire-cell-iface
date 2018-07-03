/** This is an interface to data about a waveform.  It is a contiguous
 * floating point sampling over a regular period and relative to some
 * start (eg, start time).
 */

#ifndef WIRECELL_IFACE_IWAVEFORM
#define WIRECELL_IFACE_IWAVEFORM

#include "WireCellIface/IData.h"
#include "WireCellIface/ISequence.h"


namespace WireCell {

    class IWaveform : IData<IWaveform> {
    public:
        typedef std::vector<float> sequence_type;

        virtual ~IWaveform() {}
        // The starting point of the sampling
        virtual double start() const = 0;
        // The sampling period aka bin width
        virtual double period() const = 0;
        // The collection of samples 
        virtual const sequence_type& samples() const = 0;
        
    };
}

#endif

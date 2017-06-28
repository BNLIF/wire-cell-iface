/** This interface provides access to some "filter waveform" which
 * is some discreetly sampled function. */

#ifndef WIRECELLIFACE_IFILTERWAVEFORM
#define WIRECELLIFACE_IFILTERWAVEFORM

#include "WireCellUtil/IComponent.h"
#include "WireCellUtil/Waveform.h"

namespace WireCell {

    class IFilterWaveform : public IComponent<IFilterWaveform> {
    public:
        virtual IFilterWaveform() {}

        /// Provide the filter waveform.  Note the binning of the
        /// returned waveform should be coordinated through
        /// configuration.
        virtual const Waveform::realseq_t& filter_waveform() const = 0;
    };
}

#endif

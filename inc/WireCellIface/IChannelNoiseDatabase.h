#ifndef WIRECELL_ICHANNELNOISEDATABASE
#define WIRECELL_ICHANNELNOISEDATABASE

#include "WireCellUtil/Waveform.h"
#include "WireCellUtil/IComponent.h"

namespace WireCell {

    // FIXME: this needs to be simplified into a Noise Subtraction
    // Service interface.  All these details need to be subsumed into
    // an implementation!
    class IChannelNoiseDatabase : public WireCell::IComponent<IChannelNoiseDatabase> {
    public:

	/// The data type for all frequency-space, multiplicative filters. 
	typedef WireCell::Waveform::compseq_t filter_t;
	typedef std::vector<int> channel_group_t;

	virtual ~IChannelNoiseDatabase() {};


	/// FIXME: how to handle state changes?

	/// Return the number of samples
	virtual int number_samples() const = 0;

	/// Return the sample size (time in system of units)
	virtual double sample_time() const = 0;

	/// Return a nominal baseline correction (additive offset)
	virtual double nominal_baseline(int channel) const = 0;

	/// Return simple gain correction (a multiplicative, unitless
	/// scaling) to apply to a given channel.
	virtual double gain_correction(int channel) const = 0;
	


	/// Return the filter for the RC+RC coupling response function.
	virtual const filter_t& rcrc(int channel) const = 0;

	/// Return the filter to correct any wrongly configured channels.
	virtual const filter_t& config(int channel) const  = 0;

	/// Return the filter to attenuate noise.
	virtual const filter_t& noise(int channel) const = 0;


	/// Return channel grouping for coherent noise subtraction
	virtual std::vector<channel_group_t> coherent_channels() const = 0;

	/// Return channels which are considered a'priori "bad".
	virtual channel_group_t bad_channels() const {
	    return channel_group_t();
	}

    };

}

#endif
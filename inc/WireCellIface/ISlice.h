#ifndef WIRECELLIFACE_ISLICE
#define WIRECELLIFACE_ISLICE

#include <map>

namespace WireCell {

    /// WireCell::ISlice - interface to one time slice of a frame.  A
    /// slice provides access to a collection of charge measurements
    /// on the traces which occurred in the time slice.
    class ISlice {
    public:

	typedef std::map<int,float> ChannelCharge;

	virtual ~ISlice();

	/// Return the time bin relative to some absolute time
	/// (typically the start of the frame) that this slice covers.
	virtual int tbin() const = 0;

	/// Return a mapping from channel identity number and the
	/// charge in that channel in this time slice.
	virtual const ChannelCharge& charge() const = 0;

    };

}

#endif

/**
   IChannel embodies static information about a single front end
   electronics channel.  It is associated and akin to IWire.  See also
   IElectronics.
 */

#ifndef WIRECELLIFACE_ICHANNEL
#define WIRECELLIFACE_ICHANNEL

#include "WireCellIface/IData.h"

namespace WireCell {
    class IChannel : public IData<IWire> {
    public:
        virtual ~IChannel() {}

	/// Detector-dependent, globally unique channel ID number.
	/// Negative is illegal, not guaranteed consecutive.  This
	/// same number may be called "channel" in other contexts.
        virtual int ident() const = 0;
        
	/// The wire plane ID of the zeroth segment of the wire
	/// conductor directly attached to channel input.
	virtual WirePlaneId planeid() const = 0;

        /// The channel index is the "Wire Attachment Number".  The
        /// WAN counts along points of attachment on the anode of the
        /// zero-segment wires for a given wire plane.  For MicroBooNE
        /// this is equivalent to a per plane channel index.  Likewise
        /// for protoDUNE it counts channels along the wire boards
        /// (and ignoring the fact that conductors will eventually
        /// wrap)
	virtual int index() const = 0;

        /// The chip identifier is a detector-dependent, globally
        /// unique number for the FEE amplifier ASIC in which this
        /// channel resides.
        virtual int chipid() const = 0;

        /// The chipchind is the channel index number in the chip that
        /// is this IChannel.  This is an index from 0 -
        /// N_chperchip-1.  Negative is interpreted as
        /// illegal/unknown.
        virtual int chipchind() const = 0;

        /// The zero-segment wire directly attached to channel input.
        virtual IWire::pointer wire() const = 0;

    };
}

#endif

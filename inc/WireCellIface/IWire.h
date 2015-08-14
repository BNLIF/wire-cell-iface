#ifndef WIRECELLIFACE_IWIRE
#define WIRECELLIFACE_IWIRE

#include "WireCellUtil/Point.h"
#include "WireCellIface/IData.h"
#include "WireCellIface/ISink.h"
#include "WireCellIface/ISequence.h"

#include <set>
#include <map>
#include <vector>
#include <memory>

namespace WireCell {

    /// Wire set plane/direction types.  W and Y are aliases
    enum WirePlaneType_t {kFirstPlane,
			  kUwire=0, kVwire, kWwire, kYwire=2,
			  kLastPlane=2, kNPlanes=3, kAllPlanes=4,
			  kUnknownWirePlaneType = -1};

    /// A pair of wire plane/direction type and index w/in that plane of wires
    typedef std::pair<WirePlaneType_t, int> WirePlaneIndex;


    /// Interface to information about a physical wire segment.
    class IWire : public IData<IWire> {
    public:
	virtual ~IWire();

	/// Detector-dependent, globally unique ID number.  Negative
	/// is illegal, not guaranteed consecutive.
	virtual int ident() const = 0;

	/// The plane/direction enum of the wire 
	virtual WirePlaneType_t plane() const = 0;
	
	/// Consecutive, zero-based index into an ordered sequence of
	/// wires in their plane
	virtual int index() const = 0;

	/// Detector-dependent electronics channel number, negative is illegal.
	virtual int channel() const = 0;

        /// Return the number of wire segments between the channel
        /// input and this wire.  Wire directly attached to channel
        /// input is segment==0.
        virtual int segment() const = 0;

        /// Return which side of the APA this wire exists.  Nominal or
        /// "front" face is 0, other or "back" face is 1.
        virtual int face() const = 0;

        /// Return the APA number associated with this wire.
        virtual int apa() const = 0;


	/// Return the ray representing the wire segment.
	// fixme: may want to change this to a const reference to save the copy
	virtual WireCell::Ray ray() const = 0;

	/// Return the center point of the wire.  Convenience method.
	virtual WireCell::Point center() const;

	/// Convenience function to return the plane+index pair.
	virtual WirePlaneIndex plane_index() const {
	    return WirePlaneIndex(this->plane(), this->index());
	}

    };				// class IWire

    /// Some common collections.  Note, use IWireSequence as a way to
    /// pass-by-value an iterator range.
    typedef std::vector<IWire::pointer> IWireVector;
    typedef std::pair<IWire::pointer, IWire::pointer> IWirePair;

    /// An abstract base class for anything that can sink a sequence
    /// of wires.
    typedef ISink<IWire> IWireSink;

    /** An abstract base class for a sequence of wires.
     *
     * This could simply be a typedef but it is convenient to provide
     * different names for iterators and begin()/end() to facilitate
     * any subclassing of both IWireSequence and ICellSequence.  If
     * you don't want this cruft, just inherit directly from
     * ISequence<IWire>.
     */
    class IWireSequence : virtual public ISequence<IWire> {
    public:
	typedef std::shared_ptr<IWireSequence> pointer;

	typedef IWire::base_iterator	wire_base_iterator;
	typedef IWire::iterator		wire_iterator;
	typedef IWire::iterator_range	wire_range;

	/// Actual subclass must implement:
	virtual wire_iterator wires_begin() = 0;
	virtual wire_iterator wires_end() = 0;

	virtual wire_range wires_range() { return wire_range(wires_begin(), wires_end()); }

	virtual wire_iterator begin() { return wires_begin(); };
	virtual wire_iterator end() { return wires_end(); };

    };
}

#endif

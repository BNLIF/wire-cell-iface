#ifndef WIRECELLIFACE_IWIRE
#define WIRECELLIFACE_IWIRE

#include "WireCellUtil/Point.h"
#include "WireCellUtil/Interface.h"

#include <set>
#include <map>
#include <vector>
#include <memory>

namespace WireCell {

    /// Wire set plane/direction types.  W and Y are aliases
    enum WirePlaneType_t {kFirstPlane, kUwire=0, kVwire, kWwire, kYwire=2, kLastPlane=2, kNPlanes=3, kAllPlanes=4, kUnknownWirePlaneType = -1};

    /// A pair of wire plane/direction type and index w/in that plane of wires
    typedef std::pair<WirePlaneType_t, int> WirePlaneIndex;


    /// Interface to information about a physical wire segment.
    class IWire : virtual public Interface {
    public:
	virtual ~IWire();

	/// Detector-dependent, globally unique ID number.  Negative
	/// is illegal, not guaranteed consecutive.
	virtual int ident() const = 0;

	/// The plane/direction enum of the wire 
	virtual WirePlaneType_t plane() const = 0;
	
	/// Convenience function returning the plane as a simple integer
	virtual int iplane() const { this->plane() - kFirstPlane; }

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

}


namespace WireCell {

    // No use of bare IWires, everybody shares.  Once made they are
    // forever const.  They are accessed by this pointer-like object
    // Wire.  No need for bare pointers nor references.
    typedef std::shared_ptr<const IWire> Wire;


    /// Compare two wires by their plane and index
    struct WirePlaneIndexCompare {
	bool operator() (Wire lhs, Wire rhs) const;
    };

    /// A an ordered set of wires.
    typedef std::set<Wire, WirePlaneIndexCompare> WireSet;

    /// A vector of wires.
    typedef std::vector<Wire> WireVector;

    /// A set of non-owning pointers to wires, ordered by plane and
    /// index.  Only use this when you really need a std::set.  See
    /// also WireCell::IndexedSet from the WireCellUtil package.
    typedef std::set<Wire, WirePlaneIndexCompare> WireSet;

    /// A pair of wires associated in some way
    typedef std::pair<Wire, Wire> WirePair;

    /// A mapping between wire and a floating point value
    typedef std::map<Wire, float> WireValueMap; 

    /// A mapping between wire and an integer point value
    typedef std::map<Wire, int> WireIndexMap;
	

    WIRECELL_DEFINE_INTERFACE(IWire);
}

/// Return true if two wires are identical.
bool operator==(WireCell::Wire lhs, WireCell::Wire rhs);

/// Compare two wires for inequality, first by plane, then by index
bool operator<(WireCell::Wire lhs, WireCell::Wire rhs);

/// Stream a Wire
std::ostream & operator<<(std::ostream &os, WireCell::Wire wire);

#endif

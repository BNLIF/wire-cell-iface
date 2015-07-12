#ifndef WIRECELLIFACE_IWIRE
#define WIRECELLIFACE_IWIRE

#include "WireCellUtil/Point.h"

#include <set>
#include <map>
#include <vector>

namespace WireCell {

    /// Wire set plane/direction types.  W and Y are aliases
    enum WirePlaneType_t {kFirstPlane, kUwire=0, kVwire, kWwire, kYwire=2, kLastPlane=2, kNPlanes=3, kUnknownWirePlaneType = -1};

    /// A pair of wire plane/direction type and index w/in that plane of wires
    typedef std::pair<WirePlaneType_t, int> WirePlaneIndex;


    /// Interface to information about a physical wire segment.
    class IWire {
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

	/// Return the ray representing the wire segment.
	// fixme: may want to change this to a const reference to save the copy
	virtual WireCell::Ray ray() const = 0;

	/// Return the center point of the wire.  Convenience method.
	virtual WireCell::Point center() const;

	/// Convenience function to return the plane+index pair.
	virtual WirePlaneIndex plane_index() const {
	    return WirePlaneIndex(this->plane(), this->index());
	}
	
    };


    /// Compare two wires by their plane and index
    struct WirePlaneIndexCompare {
	bool operator() (const IWire* lhs, const IWire* rhs) const;
    };


    /// A an owning store for an associated collection of wires.
    typedef std::set<IWire*, WirePlaneIndexCompare> WireStore;

    /// A vector of non-owning pointers to wires.
    typedef std::vector<const IWire*> WireVector;

    /// A set of non-owning pointers to wires, ordered by plane and
    /// index.  Only use this when you really need a std::set.  See
    /// also WireCell::IndexedSet from the WireCellUtil package.
    typedef std::set<const IWire*, WirePlaneIndexCompare> WireSet;

    /// A pair of wires associated in some way
    typedef std::pair<const IWire*, const IWire*> WirePair;

    /// A mapping between wire and a floating point value
    typedef std::map<const IWire*, float> WireValueMap; 

    /// A mapping between wire and an integer point value
    typedef std::map<const IWire*, int> WireIndexMap;
	
}

/// Return true if two wires are identical.
bool operator==(const WireCell::IWire &lhs, const WireCell::IWire &rhs);

/// Compare two wires for inequality, first by plane, then by index
bool operator<(const WireCell::IWire& lhs, const WireCell::IWire& rhs);


std::ostream & operator<<(std::ostream &os, const WireCell::IWire& wire);
std::ostream & operator<<(std::ostream &os, const WireCell::IWire* wirep);

#endif

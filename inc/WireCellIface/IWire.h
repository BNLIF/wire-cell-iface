#ifndef WIRECELLIFACE_IWIRE
#define WIRECELLIFACE_IWIRE

#include "WireCellUtil/Point.h"
#include "WireCellIface/IData.h"
#include "WireCellIface/ISink.h"
#include "WireCellIface/ISequence.h"
#include "WireCellIface/WirePlaneId.h"

#include <set>
#include <map>
#include <vector>
#include <memory>

namespace WireCell {

    
    /// Interface to information about a physical wire segment.
    class IWire : public IData<IWire> {
    public:
	virtual ~IWire();

	/// Detector-dependent, globally unique ID number.  Negative
	/// is illegal, not guaranteed consecutive.
	virtual int ident() const = 0;

	/// The ID of the plane this wire is in
	virtual WirePlaneId planeid() const = 0;
	
	/// Consecutive, zero-based index into an ordered sequence of
	/// wires in their plane
	virtual int index() const = 0;

	/// Detector-dependent electronics channel number, negative is illegal.
	virtual int channel() const = 0;

        /// Return the number of wire segments between the channel
        /// input and this wire.  Wire directly attached to channel
        /// input is segment==0.
        virtual int segment() const = 0;

	/// Return the ray representing the wire segment.
	// fixme: may want to change this to a const reference to save the copy
	virtual WireCell::Ray ray() const = 0;

	/// Return the center point of the wire.  Convenience method.
	virtual WireCell::Point center() const;

    };				// class IWire

    /// Some common collections.  Note, use IWireSequence as a way to
    /// pass-by-value an iterator range.
    typedef std::vector<IWire::pointer> IWireVector;
    typedef std::pair<IWire::pointer, IWire::pointer> IWirePair;
    struct IWireCompareIdent {
	bool operator()(const IWire::pointer& lhs, const IWire::pointer& rhs) {
	    if (lhs->ident() == rhs->ident()) {
		return lhs.get() < rhs.get(); // break tie with pointer
	    }
	    return lhs->ident() < rhs->ident();
	}
    };
    // A set ordered by wire ident
    typedef std::set<IWire::pointer, IWireCompareIdent> IWireSet;


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

    /** Adapt a collection to a sequence.
     * 
     * If you have an IWireVector, for example, and need to fit it
     * into the ISequence interface, use this adapter class.
     */
    template<class Collection>
    class IWireCollection : public IWireSequence {
	Collection m_collection;
    public:
	IWireCollection(const Collection& c) : m_collection(c.begin(),c.end()) {}
	virtual ~IWireCollection() { }
    
	virtual wire_iterator wires_begin() { return adapt(m_collection.begin()); }
	virtual wire_iterator wires_end() { return adapt(m_collection.end()); }
    
    };
}


#endif

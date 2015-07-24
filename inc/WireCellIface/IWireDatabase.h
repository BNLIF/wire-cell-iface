#ifndef WIRECELLIFACE_IWIREDATABASE
#define WIRECELLIFACE_IWIREDATABASE

#include "WireCellIface/IWireProvider.h"
#include "WireCellIface/IWireSelectors.h"

namespace WireCell {

    /** Interface providing various relational queries on the
     * wires. */
    class IWireDatabase : public IWireProvider {
    public:

	virtual ~IWireDatabase();
	
	/// Load the underling wire data.
	virtual void load(wire_range wires) = 0;

	/// Return a range of wires matching the query selector.
	virtual wire_range select(wire_selector sel) = 0;


	// old interface must die
#if 0

	/// Return a collection of wires in the given plane/direction
	/// or all of them if no direction is specified.
	virtual const WireVector& wires_in_plane(WirePlaneType_t plane = kUnknownWirePlaneType) const = 0; 
	// selector

	/// Look up a wire by it's identifier
	virtual Wire by_ident(int ident) const = 0;
	// selector

	/// Look up a wire by it's electronics channel number.
	virtual Wire by_channel_segment(int channel, int segment) const = 0;
	// selector

	/// Return all wires connected to a given channel
	virtual const WireVector& by_channel(int channel) const = 0;
	// selector

	/// Look up a wire by its plane number and index
	virtual Wire by_planeindex(WirePlaneType_t plane, int index) const = 0;
	virtual Wire by_planeindex(const WirePlaneIndex& planeindex) const = 0;
	// selector

	/// Return wire characteristic/average pitch (perpendicular
	/// distance between wires) as a distance in the System of Units.
	virtual double pitch(WirePlaneType_t plane) const = 0;
	// move to Point.h

	/// Return a characteristic/average vector which points along
	/// the pitch and has unit length.
	virtual WireCell::Point pitch_unit_vector(WirePlaneType_t plane) const = 0;
	// move to Point.h

	/// Return a characteristic/average wire angle of given plane
	/// w.r.t. the Y axis (angle is in System of Units)
	virtual double angle(WirePlaneType_t plane) const = 0;
	// move to Point.h

	/// Return the bounding box of the wire planes as a raw
	/// between two diagonal corners.
	virtual WireCell::Ray bounding_box() const = 0;
	// move to Point.h

	/// Return the geometric center of all wire planes.
	virtual WireCell::Point center() const = 0;
	// move to Point.h

	/// Return the distance from the center of the first wire to
	/// the given point projected along the direction of the
	/// plane's wire pitch.
	virtual double wire_dist(const Point& point, WirePlaneType_t plane) const = 0;
	// move to Point.h - really only need a pitch Ray + the point.

	/// Return the distance from the center of the first wire to
	/// the center of the given wire projected along the direction
	/// of the plane's wire pitch.
	virtual double wire_dist(Wire wire) const = 0;
	// move to Point.h - really only need a pitch Ray + the point.
	
	/// Given two wires, calculate their crossing point projected
	/// to the y-z plane.  Only y and z values of result are modified.
	/// Return true if point is in the extent.
	virtual bool crossing_point(Wire wire1, Wire wire2, 
				    WireCell::Point& result) const = 0;
	// move to Point.h

	/// Given two lines defined as distances measured
	/// perpendicular to the given wire plane type, calculate
	/// their crossing point projected to the y-z plane.  Only y
	/// and z values of result are modified.  Return true if point
	/// is in the extent.
	virtual bool crossing_point(double dis1, double dis2, 
				    WirePlaneType_t plane1, WirePlaneType_t plane2, 
				    WireCell::Point& result) const = 0;
	// move to Point.h

	/// Return the two wires that bound a given point in the wire
	/// plane.  If point is out not bounded on the lower distance
	/// side the first wire pointer will be NULL, etc if the point
	/// is not bounded in the higher distance side.  This
	/// implementation assumes wires are of uniform pitch and
	/// angle.
	virtual WirePair bounding_wires(const WireCell::Point& point, 
					WirePlaneType_t plane = kUnknownWirePlaneType) const = 0;
	// move to Point.h

	/// Return closest wire in the plane to the given point along
	/// the direction perpendicular to the wires of the given
	/// plane.  This implementation assumes wires are of uniform
	/// pitch and angle.
	virtual Wire closest(const WireCell::Point& point, 
			     WirePlaneType_t plane = kUnknownWirePlaneType) const = 0;
	
	// move to Point.h	
#endif
    };

    WIRECELL_DEFINE_INTERFACE(IWireDatabase);

}

#endif

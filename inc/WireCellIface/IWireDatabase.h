#ifndef WIRECELLIFACE_IWIREDATABASE
#define WIRECELLIFACE_IWIREDATABASE

#include "WireCellIface/IWire.h"

namespace WireCell {

    /** Interface providing various relational queries on the
     * wires. */
    class IWireDatabase {
    public:
	virtual ~IWireDatabase();
	
	/// Load the underling wire data.
	virtual void load(const WireCell::WireVector& wires) = 0;

	/// Return a collection of wires in the given plane/direction
	/// or all of them if no direction is specified.
	virtual const WireVector& wires_in_plane(WirePlaneType_t plane = kUnknownWirePlaneType) const = 0; 

	/// Look up a wire by it's identifier
	virtual const IWire* by_ident(int ident) const = 0;

	/// Look up a wire by it's electronics channel number.
	virtual const IWire* by_channel_segment(int channel, int segment) const = 0;

	/// Return all wires connected to a given channel
	virtual const WireVector& by_channel(int channel) const = 0;

	/// Look up a wire by its plane number and index
	virtual const IWire* by_planeindex(WirePlaneType_t plane, int index) const = 0;
	virtual const IWire* by_planeindex(const WirePlaneIndex& planeindex) const = 0;

	/// Return wire characteristic/average pitch (perpendicular
	/// distance between wires) as a distance in the System of Units.
	virtual double pitch(WirePlaneType_t plane) const = 0;

	/// Return a characteristic/average vector which points along
	/// the pitch and has unit length.
	virtual WireCell::Point pitch_unit_vector(WirePlaneType_t plane) const = 0;

	/// Return a characteristic/average wire angle of given plane
	/// w.r.t. the Y axis (angle is in System of Units)
	virtual double angle(WirePlaneType_t plane) const = 0;

	/// Return size extent in all Cartesian directions (x=0, y=1 and
	/// z=2) of all wire endpoints.  Values are length in the
	/// System of Units.  One can limit the extent to a particular
	/// wire plane, o.w. the union of all planes is assumed.
	virtual std::vector<double> extent(WirePlaneType_t plane = kUnknownWirePlaneType) const = 0;

	/// Return the geometric center of all wire planes.
	virtual WireCell::Point center() const = 0;

	/// Return min/max in a particular direction (x=0, y=1 and
	/// z=2) of all wire endpoints.  Values are length in the
	/// System of Units.  One can limit the extent to a particular
	/// wire plane, o.w. the union of all planes is assumed.
	virtual std::pair<double, double> minmax(int axis, WirePlaneType_t plane = kUnknownWirePlaneType) const = 0;

	/// Return true if point is contained in the extent of all
	/// wire planes.  The extent is considered inclusive of the
	/// center-line of the wire so exact boundary matches are
	/// consisidered contained.
	virtual bool contained(const Point& point) const = 0;

	/// Return true if point is contained in the extent of the
	/// wireplaces transverse to (and ignoring) the drift
	/// direction.  See also contained().
	virtual bool contained_yz(const Point& point) const = 0;

	/// Return the location of the point measured in the direction
	/// of wire pitch.
	virtual double wire_dist(const Point& point, WirePlaneType_t plane) const = 0;
	
	/// Return the location of the center point of the wire
	/// measured in the direction of the pitch of the wire's
	/// plane.
	virtual double wire_dist(const IWire& wire) const = 0;
	
	/// Given two wires, calculate their crossing point projected
	/// to the y-z plane.  Only y and z values of result are modified.
	/// Return true if point is in the extent.
	virtual bool crossing_point(const IWire& wire1, const IWire& wire2, 
				    WireCell::Point& result) const = 0;

	/// Given two lines defined as distances measured
	/// perpendicular to the given wire plane type, calculate
	/// their crossing point projected to the y-z plane.  Only y
	/// and z values of result are modified.  Return true if point
	/// is in the extent.
	virtual bool crossing_point(double dis1, double dis2, 
				    WirePlaneType_t plane1, WirePlaneType_t plane2, 
				    WireCell::Point& result) const = 0;

	/// Return the two wires that bound a given point in the wire
	/// plane.  If point is out not bounded on the lower distance
	/// side the first wire pointer will be NULL, etc if the point
	/// is not bounded in the higher distance side.  This
	/// implementation assumes wires are of uniform pitch and
	/// angle.
	virtual WirePair bounds(const WireCell::Point& point, 
				WirePlaneType_t plane = kUnknownWirePlaneType) const = 0;

	/// Return closest wire in the plane to the given point along
	/// the direction perpendicular to the wires of the given
	/// plane.  This implementation assumes wires are of uniform
	/// pitch and angle.
	virtual const IWire* closest(const WireCell::Point& point, 
				     WirePlaneType_t plane = kUnknownWirePlaneType) const = 0;
	
	
    };


}

#endif

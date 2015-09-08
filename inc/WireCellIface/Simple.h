#ifndef WIRECELLIFACE_SIMPLE
#define WIRECELLIFACE_SIMPLE

#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"

#include <iostream>		// debug

namespace WireCell {

    /** A wire that simply holds all its data. */
    class SimpleWire : public WireCell::IWire {
	WireCell::WirePlaneId m_wpid;
	int m_index;
	int m_channel;
	int m_segment;
	WireCell::Ray m_ray;
    public:
	SimpleWire(WireCell::WirePlaneId ident, int index, int channel,
		   const WireCell::Ray& ray, int segment = 0)
	    : m_wpid(ident),
	      m_index(index)
	    , m_channel(channel) // fixme: move imp to .cxx
	    , m_segment(segment)
	    , m_ray(ray) { }
	virtual ~SimpleWire() {}

	// this probably could overflow? switch to long int for wire ident?
	int ident() const { return m_wpid.ident() * 100000 + m_index; }

	WireCell::WirePlaneId planeid() const { return m_wpid; }
        
	int index() const { return m_index; }

	int channel() const { return m_channel; }

	WireCell::Ray ray() const { return m_ray; }

	int segment() const {return 0;}
    };


    /** A cell that simply holds all its data.
     */
    class SimpleCell : public WireCell::ICell {
	int m_ident;
	IWireVector m_wires;
	PointVector m_corners;
    
    public:
	SimpleCell(int ident,
		   const IWireVector& wires = IWireVector(),
		   const PointVector& corners = PointVector())
	    : m_ident(ident)
	    , m_wires(wires)
	    , m_corners(corners)
	{
	    std::cerr << "SimpleCell #" << ident << " with " << m_wires.size() << " wires" << std::endl;
	}
	virtual ~SimpleCell() {}

	virtual int ident() const { return m_ident; }
	
	virtual double area() const { return -1; } // fixme
	
	virtual WireCell::Point center() const {
	    if (m_corners.empty()) {
		return Point();
	    }
	    Point ret;
	    for (auto p : m_corners) {
		ret += p;
	    }
	    return ret * (1.0/m_corners.size());
	}	

	virtual WireCell::PointVector corners() const {
	    return WireCell::PointVector(m_corners.begin(), m_corners.end());
	}
	
	virtual WireCell::IWireVector wires() const {
	    return WireCell::IWireVector(m_wires.begin(), m_wires.end());
	}
    };

}

#endif

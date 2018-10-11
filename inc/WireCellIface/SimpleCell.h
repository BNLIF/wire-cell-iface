#ifndef WIRECELLIFACE_SIMPLECELL
#define WIRECELLIFACE_SIMPLECELL

#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"

#include <iostream>		// debug

namespace WireCell {


    /** A cell that simply holds all its data.
     */
    class SimpleCell : public WireCell::ICell {
	int m_ident;
	IWire::vector m_wires;
	PointVector m_corners;
    
    public:
	SimpleCell(int ident,
		   const IWire::vector& wires = IWire::vector(),
		   const PointVector& corners = PointVector())
	    : m_ident(ident)
	    , m_wires(wires)
	    , m_corners(corners)
	{
	    std::cerr << "SimpleCell #" << ident << " with " << m_wires.size() << " wires" << std::endl;
	}
	virtual ~SimpleCell();

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
	    return m_corners;
	}
	
	virtual WireCell::IWire::vector wires() const {
	    return m_wires;
	}
    };

}

#endif

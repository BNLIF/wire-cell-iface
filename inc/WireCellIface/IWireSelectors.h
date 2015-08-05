/**
   Some wire selectors.

   Fixme: this isn't really appropriate for an interface package.

 */

#ifndef WIRECELL_WIRESELECTORS
#define  WIRECELL_WIRESELECTORS

#include "WireCellIface/IWire.h"
#include <boost/function.hpp>

namespace WireCell {

    typedef boost::function<bool (IWire::pointer)> wire_selector;

    /// Select wires by plane (and apa/face)
    struct WirePlaneSelector {
	WirePlaneType_t plane;
	int apa, face;

	// Set face<0 or apa<0 to allow any, default it first face/apa.
	WirePlaneSelector(WirePlaneType_t plane = kAllPlanes, int face = 0, int apa = 0)
	    : plane(plane), apa(apa), face(face) {}

	bool operator()(IWire::pointer wire) { 
	    if (apa >= 0 && wire->apa() != apa) { return false; }
	    if (face >= 0 && wire->face() != face) { return false; }
	    if (plane == kAllPlanes) return true;
	    return wire->plane() == plane;
	}
    };
	
    // Select all wires on default apa/face
    extern wire_selector select_all_wires;

    // Select one plane on default apa/face
    extern wire_selector select_u_wires;
    extern wire_selector select_v_wires;
    extern wire_selector select_w_wires;
    extern wire_selector select_uvw_wires[3];

}

#endif

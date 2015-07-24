
#include "WireCellIface/IWireSelectors.h"

namespace WireCell {


    wire_selector select_all_wires = WirePlaneSelector(kAllPlanes, 0, 0);
    wire_selector select_u_wires = WirePlaneSelector(kUwire, 0, 0);
    wire_selector select_v_wires = WirePlaneSelector(kVwire, 0, 0);
    wire_selector select_w_wires = WirePlaneSelector(kWwire, 0, 0);
    wire_selector select_uvw_wires[3] = {
	select_u_wires,
	select_v_wires,
	select_w_wires
    };


}

#ifndef WIRECELL_IGEOMETRY
#define WIRECELL_IGEOMETRY

#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"
#include "WireCellIface/IWireSummary.h"
#include "WireCellIface/ITiling.h"

namespace WireCell {

    /** An interface bundling together all major geometry components.
     */
    class IGeometry : virtual public Interface {
    public:
	typedef std::shared_ptr<IGeometry> pointer;

	virtual ~IGeometry() {}

	virtual IWireSequence::pointer wires() = 0;
	virtual ICellSequence::pointer cells() = 0;
	virtual ITiling::pointer tiling() = 0;
	virtual IWireSummary::pointer wire_summary() = 0;

    };


    class IGeomSink : virtual public Interface {
    public:

	virtual ~IGeomSink() {}

	virtual void sink(IGeometry::pointer geom) = 0;
    };

}

#endif

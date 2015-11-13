#ifndef WIRECELL_IPOINTFIELDSINK
#define WIRECELL_IPOINTFIELDSINK

#include "WireCellIface/ISinkNode.h"
#include "WireCellUtil/Point.h"


namespace WireCell {

    /** Base class for a sink of cells. */
    class IPointFieldSink : public ISinkNode< PointVector >
    {
    public:
	virtual ~IPointFieldSink() {}

	/// supply:
	/// virtual bool insert(const std::shared_ptr<PointVector>& field);

    };

}


#endif


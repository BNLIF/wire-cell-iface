#ifndef WIRECELL_IPOINTFIELDSINK
#define WIRECELL_IPOINTFIELDSINK

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/SimpleNodes.h"
#include "WireCellUtil/Point.h"


namespace WireCell {

    /** Base class for a sink of cells. */
    class IPointFieldSink
       	: public IComponent<IPointFieldSink>
	, public IReceivingNode< PointVector >
    {
    public:
	virtual ~IPointFieldSink() {}

	/// supply:
	/// virtual bool insert(const std::shared_ptr<PointVector>& field);

    };

}


#endif


#ifndef WIRECELL_IPOINTFIELDSINK
#define WIRECELL_IPOINTFIELDSINK

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/ISink.h"
#include "WireCellUtil/Point.h"


namespace WireCell {

    /** Base class for a sink of cells. */
    class IPointFieldSink
       	: public IComponent<IPointFieldSink>
	, virtual public ISink< PointVector >
    {
    public:
	virtual ~IPointFieldSink() {}

	/// supply:
	/// virtual bool insert(const std::shared_ptr<PointVector>& field);

    };

}


#endif


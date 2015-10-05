#ifndef WIRECELL_ISCALARFIELDSINK
#define WIRECELL_ISCALARFIELDSINK

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/ISink.h"
#include "WireCellUtil/Point.h"


namespace WireCell {

    /** Base class for a sink of cells. */
    class IScalarFieldSink
       	: public IComponent<IScalarFieldSink>
	, virtual public ISink< ScalarField >
    {
    public:
	virtual ~IScalarFieldSink() {}

	/// supply:
	/// virtual bool insert(const std::shared_ptr<ScalarField>& field);

    };

}


#endif


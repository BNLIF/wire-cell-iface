#ifndef WIRECELL_ICELLVECTORSINK
#define WIRECELL_ICELLVECTORSINK

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IReceiving.h"
#include "WireCellIface/ICell.h"

namespace WireCell {

    /** Base class for a sink of a vector of cells. */
    class ICellVectorSink
       	: public IComponent<ICellVectorSink>
	, virtual public IReceiving<ICell::vector>
    {
    public:
	virtual ~ICellVectorSink() {}

	/// supply:
	/// virtual bool insert(const ICell::shared_vector& cells);

    };

}


#endif


#ifndef WIRECELL_ICELLVECTORSINK
#define WIRECELL_ICELLVECTORSINK

#include "WireCellIface/ISinkNode.h"
#include "WireCellIface/ICell.h"

namespace WireCell {

    /** Base class for a sink of a vector of cells. */
    class ICellVectorSink : public ISinkNode<ICell::vector>
    {
    public:
	virtual ~ICellVectorSink() {}

	/// supply:
	/// virtual bool operator()(const ICell::shared_vector& cells);

    };

}


#endif


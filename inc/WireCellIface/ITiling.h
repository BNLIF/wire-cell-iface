#ifndef WIRECELL_ITILING
#define WIRECELL_ITILING

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IConverter.h"
#include "WireCellIface/ICellSummary.h"

namespace WireCell {

    /** A tiling is a processor which produces a cell summary object
     * based on the input cell vector.
     */
    class ITiling
	: public IComponent<ITiling>
	, virtual public IConverter<ICell::vector, ICellSummary>
    {
    public:

	virtual ~ITiling() {}

    };

}

#endif

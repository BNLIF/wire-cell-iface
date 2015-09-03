#ifndef WIRECELL_ITILING
#define WIRECELL_ITILING

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IProcessor.h"
#include "WireCellIface/ICellSummary.h"

namespace WireCell {

    /** A tiling is a processor which produces a cell summary object
     * based on the input cell vector.
     */
    class ITiling
	: public IComponent<ITiling>
	, public ISink<ICellVector>
	, public ISource<ICellSummary::pointer>
    {
    public:

	virtual ~ITiling() {}

    };

}

#endif

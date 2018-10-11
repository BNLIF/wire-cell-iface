#ifndef WIRECELL_ITILING
#define WIRECELL_ITILING

#include "WireCellIface/IFunctionNode.h"
#include "WireCellIface/ICellSummary.h"

namespace WireCell {

    /** A tiling is a function node which produces a cell summary object
     * based on the input cell vector.
     */
    class ITiling : public IFunctionNode<ICell::vector, ICellSummary>
    {
    public:

	virtual ~ITiling() ;

	virtual std::string signature() {
	   return typeid(ITiling).name();
	}

    };

}

#endif

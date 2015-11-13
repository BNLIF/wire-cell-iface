#ifndef WIRECELL_ICELLMAKER
#define WIRECELL_ICELLMAKER

#include "WireCellIface/IFunctionNode.h"
#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"

namespace WireCell {

    /** A cell maker produces a vector of cells from a vector of wires.
     */
    class ICellMaker : public IFunctionNode<IWire::vector, ICell::vector>
    {
    public:
	virtual ~ICellMaker() {}
	
    };

}

#endif


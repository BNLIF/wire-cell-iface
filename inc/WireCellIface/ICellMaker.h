#ifndef WIRECELL_ICELLMAKER
#define WIRECELL_ICELLMAKER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/SimpleNodes.h"
#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"

namespace WireCell {

    /** A cell maker is a processor component which outputs a
     * collection of cells associated with the input collection or
     * wires.
     */
    class ICellMaker
	: public IComponent<ICellMaker> 
	, public IConverterNode<IWire::vector,ICell::vector>
    {
    public:
	virtual ~ICellMaker() {}
	
    };

}

#endif


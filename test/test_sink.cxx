#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"
#include "WireCellIface/IProcessor.h"

#include <iostream>

using namespace WireCell;


class MyWireSink : public ISink<IWireVector>
{
    bool sink(const IWireVector& vec) {
	for (auto wire : vec) {
	    std::cout << wire->ident() << std::endl;
	}
    }
};

class MyCellSink : public ISink<ICellVector>
{
    bool sink(const ICellVector& vec) {
	for (auto cell : vec) {
	    std::cout << cell->ident() << std::endl;
	}
    }
};

int main()
{
    MyWireSink mws;
    MyCellSink mcs;

    return 0;
}

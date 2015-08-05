#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"

#include <iostream>

using namespace WireCell;


class MyWireSink : public IWireSink
{
    void sink(const IWireSequence::iterator_range& range) {
	for (auto it : range) {
	    const IWire& wire = *it;
	    std::cout << wire.ident() << std::endl;
	}
    }
};

class MyCellSink : public ICellSink
{
    void sink(const ICellSequence::iterator_range& range) {
	for (auto it : range) {
	    const ICell& cell = *it;
	    std::cout << cell.ident() << std::endl;
	}
    }
};

int main()
{
    MyWireSink mws;
    MyCellSink mcs;

    return 0;
}

#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"


class MyWireSink : public WireCell::IWireSink
{
    void sink(WireCell::wire_iterator begin, WireCell::wire_iterator end) {
	for (auto it = begin; it != end; ++it) {
	    const WireCell::IWire& wire = **it;
	    std::cout << wire.ident() << std::endl;
	}
    }
};

class MyCellSink : public WireCell::ICellSink
{
    void sink(WireCell::cell_iterator begin, WireCell::cell_iterator end) {
	for (auto it = begin; it != end; ++it) {
	    const WireCell::ICell& cell = **it;
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

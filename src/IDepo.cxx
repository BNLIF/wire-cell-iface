#include "WireCellIface/IDepo.h"
using namespace WireCell;

IDepoVector WireCell::depo_chain(IDepo::pointer last)
{
    IDepoVector ret;
    while (true) {
	ret.push_back(last);
	last = last->prior();
	if (!last) { break; }
    }
    return ret;
}


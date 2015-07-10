#include "WireCellIface/IWire.h"


WireCell::IWire::~IWire()
{
}



bool WireCell::WirePlaneIndexCompare ::operator() (const IWire* a, const IWire* b) const
{
    return *a < *b;
}


bool operator==(const WireCell::IWire &lhs, const WireCell::IWire &rhs) 
{
    return lhs.ident() == rhs.ident();
}

bool operator<(const WireCell::IWire& lhs, const WireCell::IWire& rhs)
{
    if (lhs.plane() < rhs.plane()) {
	return true;
    }
    return lhs.index() < rhs.index();
}


std::ostream & operator<<(std::ostream &os, const WireCell::IWire& wire)
{
    os << "<WIRE " << wire.ident() << ">";
}

std::ostream & operator<<(std::ostream &os, const WireCell::IWire* wirep)
{
    os << *wirep;
    return os;
}

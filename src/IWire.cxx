#include "WireCellIface/IWire.h"


WireCell::IWire::~IWire()
{
}


WireCell::Point WireCell::IWire::center() const
{
    Ray seg = ray();
    return 0.5*(seg.first + seg.second);
}

bool WireCell::WirePlaneIndexCompare ::operator() (const IWire* lhs,
						   const IWire* rhs) const
{
    return (*lhs) < (*rhs);
}


bool operator==(const WireCell::IWire &lhs, const WireCell::IWire &rhs) 
{
    return lhs.ident() == rhs.ident();
}

bool operator<(const WireCell::IWire& lhs, const WireCell::IWire& rhs)
{
    if (lhs.plane() == rhs.plane()) {
	return lhs.index() < rhs.index();
    }
    return lhs.plane() < rhs.plane();
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

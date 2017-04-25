#include "WireCellIface/ICell.h"

WireCell::ICell::~ICell()
{
}

std::ostream & operator<<(std::ostream &os, const WireCell::ICell& cell)
{
    os << "<CELL " << cell.ident() << ">";
    return os;
}

std::ostream & operator<<(std::ostream &os, const WireCell::ICell* cellp)
{
    os << *cellp;
    return os;
}


bool operator==(const WireCell::ICell &lhs, const WireCell::ICell &rhs)
{
    return lhs.ident() == rhs.ident();
}


bool operator<(const WireCell::ICell& lhs, const WireCell::ICell &rhs)
{
    return lhs.ident() < rhs.ident();
}

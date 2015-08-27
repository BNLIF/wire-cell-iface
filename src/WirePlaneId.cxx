#include "WireCellIface/WirePlaneId.h"

using namespace WireCell;

static const int layer_mask = 0x7;
static const int face_shift = 3;
static const int apa_shift = 4;

WireCell::WirePlaneId::WirePlaneId(WirePlaneLayer_t layer, int face, int apa)
    : m_pack( (((int)layer)&layer_mask) | (face << face_shift) | (apa<<apa_shift))
{
}

int WireCell::WirePlaneId::ident() const
{
    return m_pack;
}
WireCell::WirePlaneLayer_t WireCell::WirePlaneId::layer() const
{
    return WirePlaneLayer_t(ilayer());
}
int WireCell::WirePlaneId::ilayer() const
{
    return m_pack & layer_mask;
}

int WireCell::WirePlaneId::index() const
{
    switch (layer()) {
    case kUlayer : return 0;
    case kVlayer : return 1;
    case kWlayer : return 2;
    }
    return -1;
}
int WireCell::WirePlaneId::face() const
{
    return (m_pack&(1<<face_shift))>>3;
}
int WireCell::WirePlaneId::apa() const
{
    return m_pack>>apa_shift;
}

WireCell::WirePlaneId::operator bool() const
{
    int ind = index();
    return 0 <= ind && ind < 3;
}

bool WireCell::WirePlaneId::operator==(const WirePlaneId& rhs)
{
    return m_pack == rhs.m_pack;
}

bool WireCell::WirePlaneId::operator!=(const WirePlaneId& rhs)
{
    return !(*this == rhs);
}

bool WireCell::WirePlaneId::operator<(const WirePlaneId& rhs)
{
    if (!*this || !rhs) { return false; }

    if (apa() == rhs.apa()) {
	if (face() == rhs.face()) {
	    return index() < rhs.index();
	}
	return face() < rhs.face();
    }
    return apa() < rhs.apa();
}


std::ostream& operator<<(std::ostream& o, const WireCell::WirePlaneId& wpid)
{
    o << "[WirePlaneId "<< wpid.ident() << " ind:" << wpid.index() << " layer:" << wpid.layer() << " apa:" << wpid.apa() << " face:" << wpid.face();
    if (!wpid) { o << " bogus"; }
    o << "]";
    return o;
}

std::ostream& operator<<(std::ostream& o, const WireCell::WirePlaneLayer_t& layer)
{
    switch (layer) {
    case WireCell::kUlayer : o << "<U>"; break;
    case WireCell::kVlayer : o << "<V>"; break;
    case WireCell::kWlayer : o << "<W>"; break;
    default: o << "<?>"; break;
    }
    return o;
}
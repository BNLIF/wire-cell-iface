#ifndef WIRECELLIFACE_TEST_MYWIRE
#define WIRECELLIFACE_TEST_MYWIRE

#include "WireCellIface/IWire.h"
#include "WireCellUtil/Point.h"

class MyWire : public WireCell::IWire {
    WireCell::WirePlaneType_t m_plane;
    int m_index;
    WireCell::Ray m_ray;

public:
    MyWire(WireCell::WirePlaneType_t plane, int index, const WireCell::Ray& ray)
	: m_plane(plane), m_index(index), m_ray(ray)
    {}
    virtual ~MyWire() {}

    int ident() const {
	int iplane = int(m_plane);
	++iplane;
	return iplane*100000 + m_index;
    }

    WireCell::WirePlaneType_t plane() const { return m_plane; }
	
    int index() const { return m_index; }

    int channel() const { return ident(); }

    WireCell::Ray ray() const { return m_ray; }

    int segment() const {return 0;}
    int face() const {return 0;}
    int apa() const {return 0;}


};

#endif

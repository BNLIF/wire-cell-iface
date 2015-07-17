#include "WireCellIface/IWire.h"
#include "WireCellUtil/Testing.h"

#include <iostream>

using namespace WireCell;
using namespace std;

class MyWire : public IWire {
    WirePlaneType_t m_plane;
    int m_index;
    Ray m_ray;

public:
    MyWire(WirePlaneType_t plane, int index, const Ray& ray)
	: m_plane(plane), m_index(index), m_ray(ray)
    {}
    virtual ~MyWire() {}

    int ident() const {
	int iplane = m_plane - kFirstPlane;
	++iplane;
	return iplane*100000 + m_index;
    }

    WirePlaneType_t plane() const { return m_plane; }
	
    int index() const { return m_index; }

    int channel() const { return ident(); }

    WireCell::Ray ray() const { return m_ray; }

};


int main()
{
    Wire u0(new MyWire(kUwire, 0, Ray()));
    Wire u1(new MyWire(kUwire, 1, Ray()));
    Wire v0(new MyWire(kVwire, 0, Ray()));
    Wire v1(new MyWire(kVwire, 1, Ray()));
    Wire w0(new MyWire(kWwire, 0, Ray()));
    Wire w1(new MyWire(kWwire, 1, Ray()));

    Assert (u0 < u1);
//fixme: define
//    Assert (u0 != u1);
    Assert (u1 < v0);
    Assert (u1 < w1);
//    Assert (w1 > w0);
    Assert (u0 == u0);
//    Assert (w0 > v1);
    
}

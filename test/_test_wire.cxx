#include "WireCellIface/IWire.h"
#include "WireCellUtil/Testing.h"

#include "MyWire.h"

#include <iostream>

using namespace WireCell;
using namespace std;

typedef std::vector<MyWire*> RawVector;
MyWire* make_wire(RawVector& store, WirePlaneLayer_t layer, int ind)
{
    MyWire* w = new MyWire(layer, ind, Ray());
    store.push_back(w);
    cerr << "make_wire(" << layer << ", " << ind << ") -> " << store.size() << endl;
    return w;
}

int main()
{

    RawVector rawvec;
    typedef IWire::pointer Wire;

    make_wire(rawvec, kUlayer, 0);
    make_wire(rawvec, kUlayer, 1);
    make_wire(rawvec, kVlayer, 0);
    make_wire(rawvec, kVlayer, 1);
    make_wire(rawvec, kWlayer, 0);
    make_wire(rawvec, kWlayer, 1);


    // Convert raw pointer to one using shared_ptr
    typedef std::vector<IWire::pointer> CookedVector;
    CookedVector cooked(rawvec.begin(), rawvec.end());

    // Two ways to convert STL container of shared_ptrs to facade over abstract iterator:

    //IteratorAdapter<CookedVector::const_iterator, IWire::base_iterator> adapted(cooked.begin());
    IWireSequence::iterator facade_begin = IWireSequence::adapt(cooked.begin());
    IWireSequence::iterator facade_end = IWireSequence::adapt(cooked.end());
    for (auto it = facade_begin; it != facade_end; ++it) {
	IWire::pointer wire = *it;
	cerr << "facade: " << wire->ident() << endl;
    }
    
    // Alternative of the above to make a range and use pretty C++11 loop
    SequenceAdapter<IWire> range(cooked.begin(), cooked.end());
    for(auto wire : range) {
	cerr << "range: " << wire->ident() << endl;
    }

    return 0;
}

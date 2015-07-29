#include "WireCellIface/IWire.h"
#include "WireCellIface/ICell.h"

#include "MyWire.h"
#include <vector>
#include <iostream>

class MyCell : public WireCell::ICell {
public:
    virtual ~MyCell() {}
    int ident() const { return 0; }

    double area() const { return 0.0; }

    WireCell::Point center() const { return WireCell::Point(); }

    WireCell::PointVector corners() const { return WireCell::PointVector(); }
};


class MyWireSequence : public WireCell::IWireSequence, public WireCell::ICellSequence {
public:

    typedef std::vector<MyWire*> MyWireStore;
    typedef std::vector<MyCell*> MyCellStore;

    // // We can typedef these to general names because we only implement
    // // a single sequence ABC.
    // typedef WireCell::IWireSequence::wire_base_iterator base_iterator;
    // typedef WireCell::IWireSequence::wire_iterator iterator;

    typedef WireCell::IteratorAdapter< MyWireStore::const_iterator, WireCell::wire_base_iterator > my_wire_iterator;
    typedef WireCell::IteratorAdapter< MyCellStore::const_iterator, WireCell::cell_base_iterator > my_cell_iterator;    


    MyWireSequence() {
	// just add some junk
	m_wire_store.push_back(new MyWire(WireCell::kUwire, 0, WireCell::Ray()));
	m_wire_store.push_back(new MyWire(WireCell::kUwire, 1, WireCell::Ray()));
	m_wire_store.push_back(new MyWire(WireCell::kVwire, 0, WireCell::Ray()));
	m_wire_store.push_back(new MyWire(WireCell::kVwire, 1, WireCell::Ray()));
	m_wire_store.push_back(new MyWire(WireCell::kWwire, 0, WireCell::Ray()));
	m_wire_store.push_back(new MyWire(WireCell::kWwire, 1, WireCell::Ray()));
    }

    virtual WireCell::wire_iterator wires_begin() const {
	return my_wire_iterator(m_wire_store.begin());
    }
    virtual WireCell::wire_iterator wires_end() const {
	return my_wire_iterator(m_wire_store.end());
    }
    virtual size_t wires_size() const { return m_wire_store.size(); }

    virtual WireCell::cell_iterator cells_begin() const {
	return my_cell_iterator(m_cell_store.begin());
    }
    virtual WireCell::cell_iterator cells_end() const {
	return my_cell_iterator(m_cell_store.end());
    }
    virtual size_t cells_size() const { return m_cell_store.size(); }
private:
    MyWireStore m_wire_store;
    MyCellStore m_cell_store;
};


int main()
{
    using namespace std;
    using namespace WireCell;
    MyWireSequence mws;

    cout << "#wires: " << mws.wires_size() << ", #cells: " << mws.cells_size() << endl;

    for (auto it = mws.wires_begin(); it != mws.wires_end(); ++it) {
	const IWire& wire = **it;
	cout << wire.ident() << endl;
    }

    for (auto it = mws.cells_begin(); it != mws.cells_end(); ++it) {
	const ICell& cell = **it;
	cout << cell.ident() << endl;
    }
    

    return 0;
}

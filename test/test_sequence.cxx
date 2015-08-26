#include "MyWire.h"
#include "MyCell.h"
#include <vector>
#include <iostream>

#include <boost/range.hpp>

using namespace WireCell;

class MyWireSequence : virtual public IWireSequence,
		       virtual public ICellSequence {
public:

    typedef std::vector<IWire::pointer> MyWireStore;
    typedef std::vector<ICell::pointer> MyCellStore;

    MyWireSequence() {
	// just add some junk
	m_wire_store.push_back(IWire::pointer(new MyWire(kUlayer, 0, Ray())));
	m_wire_store.push_back(IWire::pointer(new MyWire(kUlayer, 1, Ray())));
	m_wire_store.push_back(IWire::pointer(new MyWire(kVlayer, 0, Ray())));
	m_wire_store.push_back(IWire::pointer(new MyWire(kVlayer, 1, Ray())));
	m_wire_store.push_back(IWire::pointer(new MyWire(kWlayer, 0, Ray())));
	m_wire_store.push_back(IWire::pointer(new MyWire(kWlayer, 1, Ray())));

	m_cell_store.push_back(ICell::pointer(new MyCell(0, 1.0)));
	m_cell_store.push_back(ICell::pointer(new MyCell(1, 2.0)));
	m_cell_store.push_back(ICell::pointer(new MyCell(2, 3.0)));
	m_cell_store.push_back(ICell::pointer(new MyCell(3, 4.0)));
	m_cell_store.push_back(ICell::pointer(new MyCell(4, 5.0)));
    }

    virtual wire_iterator wires_begin() {
	return IWireSequence::adapt(m_wire_store.begin());
    }
    virtual wire_iterator wires_end() {
	return IWireSequence::adapt(m_wire_store.end());
    }

    virtual cell_iterator cells_begin() {
	return ICellSequence::adapt(m_cell_store.begin());
    }
    virtual cell_iterator cells_end() {
	return ICellSequence::adapt(m_cell_store.end());
    }

private:
    MyWireStore m_wire_store;
    MyCellStore m_cell_store;
};


int main()
{
    using namespace std;
    using namespace WireCell;
    MyWireSequence mws;

    cout << "#wires: " << boost::distance(mws.wires_range())
	 << ", #cells: " << boost::distance(mws.cells_range()) << endl;

    for (auto it = mws.wires_begin(); it != mws.wires_end(); ++it) {
	const IWire& wire = **it;
	cout << "wire: " << wire.ident() << endl;
    }

    for (auto it = mws.cells_begin(); it != mws.cells_end(); ++it) {
	const ICell& cell = **it;
	cout << "cell: " << cell.ident() << endl;
    }
    

    return 0;
}

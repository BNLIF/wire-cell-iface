#ifndef WIRECELLIFACE_ICELLPROVIDER
#define WIRECELLIFACE_ICELLPROVIDER

#include "WireCellIface/ICell.h"

namespace WireCell {

    /** WireCell::ICellProvider - interface which provides access to a
     * definitive source of ICell objects */
    class ICellProvider {
    public:
	virtual ~ICellProvider();
	
	/// Return the all the cells the interface provides
	virtual const WireCell::CellVector& cells() const = 0;
	
    };


}

#endif

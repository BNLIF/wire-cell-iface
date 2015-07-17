#ifndef WIRECELLIFACE_ICELLPROVIDER
#define WIRECELLIFACE_ICELLPROVIDER

#include "WireCellIface/ICell.h"

namespace WireCell {

    /** Interface providing access to a definitive source of
     * WireCell::ICell objects. */
    class ICellProvider : virtual public Interface{
    public:
	virtual ~ICellProvider();
	
	/// Lend access to all the cells the interface provides.
	virtual const WireCell::CellSet& cells() const = 0;
	

    };

    WIRECELL_DEFINE_INTERFACE(ICellProvider);

}

#endif

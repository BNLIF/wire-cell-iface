#ifndef WIRECELLIFACE_ICELLPROVIDER
#define WIRECELLIFACE_ICELLPROVIDER

#include "WireCellIface/ICellIterator.h"

namespace WireCell {

    /** Interface providing access to a definitive source of
     * WireCell::ICell objects. */
    class ICellProvider : virtual public Interface{
    public:
	virtual ~ICellProvider();
	
	/// Return iterator to first cell provided.
	virtual cell_iterator cells_begin() = 0;

	/// Return iterator to one past last cell provided.
	virtual cell_iterator cells_end() = 0;


    };

    WIRECELL_DEFINE_INTERFACE(ICellProvider);

}

#endif

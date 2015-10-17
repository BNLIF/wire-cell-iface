#ifndef WIRECELLIFACE_ICHANNELCELLSELECTOR
#define WIRECELLIFACE_ICHANNELCELLSELECTOR

#include "WireCellIface/IConverter.h"

#include "WireCellIface/IChannelSlice.h"
#include "WireCellIface/ICellSlice.h"

#include "WireCellUtil/IComponent.h"

namespace WireCell {

    /** A channel-cell selector produce a subset of all cells are
     * associated with a given channel slice. 
     */
    class IChannelCellSelector
	: public IComponent<IChannelCellSelector>
	, virtual public IConverter<IChannelSlice, ICellSlice>
    {
    public:
	virtual ~IChannelCellSelector() {}

	/// Deliver all cells to the selector for later use.
	// fixme: handle by the implementation constructor?
	virtual void set_cells(const ICell::shared_vector& all_cells) = 0;
    };
}

#endif


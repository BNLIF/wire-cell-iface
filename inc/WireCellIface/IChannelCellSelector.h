#ifndef WIRECELLIFACE_ICHANNELCELLSELECTOR
#define WIRECELLIFACE_ICHANNELCELLSELECTOR

#include "WireCellIface/IJoinNode.h"

#include "WireCellIface/IChannelSlice.h"
#include "WireCellIface/ICellSlice.h"
#include "WireCellIface/ICell.h"

#include "WireCellUtil/IComponent.h"

namespace WireCell {

    /** A channel-cell selector produce a subset of all cells are
     * associated with a given channel slice. 
     */
    class IChannelCellSelector : public IJoinNode<std::tuple<IChannelSlice, ICell::vector>, ICellSlice>
    {
    public:
	virtual ~IChannelCellSelector() {}

	virtual std::string signature() {
	   return typeid(IChannelCellSelector).name();
	}

    };
}

#endif


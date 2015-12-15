#ifndef WIRECELL_IPLANESLICEMERGER
#define WIRECELL_IPLANESLICEMERGER

#include "WireCellIface/IJoinNode.h"
#include "WireCellIface/IPlaneSlice.h"

#include <string>

namespace WireCell {

    class IPlaneSliceMerger : public IJoinNode<IPlaneSlice, IPlaneSlice::vector>
    {
    public:
	virtual ~IPlaneSliceMerger() {}

	virtual std::string signature() {
	   return typeid(IPlaneSliceMerger).name();
	}
    };
}

#endif

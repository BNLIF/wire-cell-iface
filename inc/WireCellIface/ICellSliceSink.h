#ifndef WIRECELL_ICELLSLICESNINK
#define WIRECELL_ICELLSLICESNINK

#include "WireCellIface/ISinkNode.h"
#include "WireCellIface/ICellSlice.h"

namespace WireCell {

    class ICellSliceSink : public ISinkNode<ICellSlice>
    {
    public:
	virtual ~ICellSliceSink() {}

	virtual std::string signature() {
	   return typeid(ICellSliceSink).name();
	}

    };
}
#endif

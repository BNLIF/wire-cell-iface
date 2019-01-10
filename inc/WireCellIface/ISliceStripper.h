#ifndef WIRECELL_ISLICESTRIPPER
#define WIRECELL_ISLICESTRIPPER

#include "WireCellIface/ISlice.h"
#include "WireCellIface/IStripSet.h"
#include "WireCellIface/IFunctionNode.h"

namespace WireCell {

    class ISliceStripper : public IFunctionNode<ISlice, IStripSet> {
    public:
	typedef std::shared_ptr<ISliceStripper> pointer;

	virtual ~ISliceStripper() ;

	virtual std::string signature() {
	   return typeid(ISliceStripper).name();
	}

	// supply:
	// virtual bool operator()(const input_pointer& in, output_pointer& out);
    };
}

#endif

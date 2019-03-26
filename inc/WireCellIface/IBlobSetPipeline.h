#ifndef WIRECELL_IBLOBSETPIPELINE
#define WIRECELL_IBLOBSETPIPELINE

#include "WireCellIface/IFunctionNode.h"
#include "WireCellIface/IBlobSet.h"

namespace WireCell {

    class IBlobSetPipeline : public IFunctionNode<IBlobSet::vector, IBlobSet::vector>
    {
    public:
    public:
	typedef std::shared_ptr<IBlobSetPipeline> pointer;

	virtual ~IBlobSetPipeline() ;

	virtual std::string signature() {
	   return typeid(IBlobSetPipeline).name();
	}

	// supply:
	// virtual bool operator()(const input_pointer& in, output_pointer& out);

    };
}

#endif

#ifndef WIRECELL_ITILER
#define WIRECELL_ITILER

#include "WireCellIface/IFunctionNode.h"
#include "WireCellIface/IStripSet.h"
#include "WireCellIface/IBlobSet.h"

namespace WireCell {

    class ITiler :: IFunctionNode<IStripSet, IBlobSet> {
    public:
        
	typedef std::shared_ptr<ITiler> pointer;

	virtual ~ITiler() ;

	virtual std::string signature() {
	   return typeid(ITiler).name();
	}

	// supply:
	// virtual bool operator()(const input_pointer& in, output_pointer& out);
    };
}

#endif

/**  A tiling consumes a set of stripes and produces a set of blobs.
 */

#ifndef WIRECELL_ITILING
#define WIRECELL_ITILING

#include "WireCellIface/IFunctionNode.h"
#include "WireCellIface/IStripeSet.h"
#include "WireCellIface/IBlobSet.h"

namespace WireCell {

    class ITiling : IFunctionNode<IStripeSet, IBlobSet> {
    public:
        
	typedef std::shared_ptr<ITiling> pointer;

	virtual ~ITiling() ;

	virtual std::string signature() {
	   return typeid(ITiling).name();
	}

	// supply:
	// virtual bool operator()(const input_pointer& in, output_pointer& out);
    };
}

#endif

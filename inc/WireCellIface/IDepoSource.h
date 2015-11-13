#ifndef WIRECELL_IDEPOSOURCE
#define WIRECELL_IDEPOSOURCE

#include "WireCellIface/ISourceNode.h"
#include "WireCellIface/IDepo.h"

namespace WireCell {

    /** A depo source is a node that generates IDepo objects.
     */
    class IDepoSource : public ISourceNode<IDepo>
    {
    public:
	virtual ~IDepoSource() {}

	// supply:
	// virtual bool extract(IDepo::pointer& depo);

    };


}

#endif

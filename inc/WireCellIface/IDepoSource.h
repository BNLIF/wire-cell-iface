#ifndef WIRECELL_IDEPOSOURCE
#define WIRECELL_IDEPOSOURCE

#include "WireCellIface/SimpleNodes.h"
#include "WireCellIface/IDepo.h"

namespace WireCell {

    /** A depo source is a sending node that generates IDepos.
     */
    class IDepoSource : public ISendingNode<IDepo>
    {
    public:
	virtual ~IDepoSource() {}

	// supply:
	// virtual bool extract(IDepo::pointer& depo);

    };


}

#endif

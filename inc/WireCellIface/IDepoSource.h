#ifndef WIRECELL_IDEPOSOURCE
#define WIRECELL_IDEPOSOURCE

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/ISource.h"
#include "WireCellIface/IDepo.h"

namespace WireCell {

    /** A depo source is something that generates IDepos.
     */
    class IDepoSource
	: public IComponent<IDepoSource>
	, public ISource<IDepo>
    {
    public:
	virtual ~IDepoSource() {}

	// supply:
	// virtual bool extract(IDepo::pointer& depo);

    };


}

#endif

#ifndef WIRECELL_IWIRESUMMARIZER
#define WIRECELL_IWIRESUMMARIZER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IProcessor.h"
#include "WireCellIface/IWireSummary.h"

namespace WireCell {

    class IWireSummarizer
	: public IComponent<IWireSummarizer>
	, public IProcessor
	, public ISink<IWireVector>
	, public ISource<IWireSummary::pointer>
    {
    public:
	virtual ~IWireSummarizer() {}
    };
}

#endif

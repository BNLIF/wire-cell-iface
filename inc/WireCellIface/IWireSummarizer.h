#ifndef WIRECELL_IWIRESUMMARIZER
#define WIRECELL_IWIRESUMMARIZER

#include "WireCellIface/SimpleNodes.h"
#include "WireCellIface/IWireSummary.h"

#include "WireCellUtil/IComponent.h"

namespace WireCell {

    class IWireSummarizer
	: public IComponent<IWireSummarizer>
	, public IConverterNode<IWire::vector, IWireSummary>
    {
    public:
	virtual ~IWireSummarizer() {}
    };
}

#endif

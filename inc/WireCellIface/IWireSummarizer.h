#ifndef WIRECELL_IWIRESUMMARIZER
#define WIRECELL_IWIRESUMMARIZER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IConverter.h"
#include "WireCellIface/IWireSummary.h"

namespace WireCell {

    class IWireSummarizer
	: public IComponent<IWireSummarizer>
	, public IConverter<IWireVector, IWireSummary::pointer>
    {
    public:
	virtual ~IWireSummarizer() {}
    };
}

#endif

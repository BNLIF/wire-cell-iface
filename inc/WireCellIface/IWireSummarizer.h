#ifndef WIRECELL_IWIRESUMMARIZER
#define WIRECELL_IWIRESUMMARIZER

#include "WireCellIface/IConverter.h"
#include "WireCellIface/IWireSummary.h"

#include "WireCellUtil/IComponent.h"

namespace WireCell {

    class IWireSummarizer
	: public IComponent<IWireSummarizer>
	, public IConverter<IWireVector, IWireSummary>
    {
    public:
	virtual ~IWireSummarizer() {}
    };
}

#endif

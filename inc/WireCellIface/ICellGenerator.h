#ifndef WIRECELLIFACE_ICELLGENERATOR
#define WIRECELLIFACE_ICELLGENERATOR

#include "WireCellIface/ICell.h"
#include "WireCellIface/IWireDatabase.h"

namespace WireCell {

    /** Interface to something that generates ICells. */
    class ICellGenerator {
    public:
	virtual ~ICellGenerator();

	// Generate your cells.
	virtual void generate(const WireCell::IWireDatabase& wdb) = 0;
    };


}

#endif

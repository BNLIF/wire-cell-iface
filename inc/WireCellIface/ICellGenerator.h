#ifndef WIRECELLIFACE_ICELLGENERATOR
#define WIRECELLIFACE_ICELLGENERATOR

#include "WireCellIface/ICell.h"
#include "WireCellIface/IWireDatabase.h"

namespace WireCell {

    /** Interface to something that generates ICells. */
    class ICellGenerator : virtual public Interface {
    public:
	virtual ~ICellGenerator();

	// Generate your cells.
	virtual void generate(const WireCell::IWireDatabasePtr wdb) = 0;
    };

    WIRECELL_DEFINE_INTERFACE(ICellGenerator);

}

#endif

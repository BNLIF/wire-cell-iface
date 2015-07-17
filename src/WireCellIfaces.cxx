#include "WireCellIface/IWireGenerator.h"
#include "WireCellIface/ICellGenerator.h"

#include "WireCellIface/IWireProvider.h"
#include "WireCellIface/ICellProvider.h"

#include "WireCellIface/IWireDatabase.h"
#include "WireCellIface/ICellDatabase.h"

#include "WireCellIface/ITrace.h"
#include "WireCellIface/IFrame.h"
#include "WireCellIface/ISlice.h"

#include "WireCellIface/IConfigurable.h"

#include "WireCellIface/IWireParameters.h"


WireCell::IWireGenerator::~IWireGenerator() { }
WireCell::ICellGenerator::~ICellGenerator() { }

WireCell::IWireProvider::~IWireProvider() { }
WireCell::ICellProvider::~ICellProvider() { }

WireCell::IWireDatabase::~IWireDatabase() { }
WireCell::ICellDatabase::~ICellDatabase() { }

WireCell::ITrace::~ITrace() { }
WireCell::IFrame::~IFrame() { }
WireCell::ISlice::~ISlice() { }

WireCell::IConfigurable::~IConfigurable() { }
WireCell::IWireParameters::~IWireParameters() { }

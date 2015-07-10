#include "WireCellIface/IWireProvider.h"
#include "WireCellIface/ICellProvider.h"

#include "WireCellIface/IWireDatabase.h"
#include "WireCellIface/ICellDatabase.h"

#include "WireCellIface/ITrace.h"
#include "WireCellIface/IFrame.h"
#include "WireCellIface/ISlice.h"

#include "WireCellIface/Interface.h"


WireCell::Interface::~Interface() { }

WireCell::IWireProvider::~IWireProvider() { }
WireCell::ICellProvider::~ICellProvider() { }

WireCell::ICellDatabase::~ICellDatabase() { }
WireCell::IWireDatabase::~IWireDatabase() { }

WireCell::ITrace::~ITrace() { }
WireCell::IFrame::~IFrame() { }
WireCell::ISlice::~ISlice() { }







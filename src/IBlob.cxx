#include "WireCellIface/IBlob.h"

WireCell::IBlob::~IBlob()
{
}     

/// Return true if two blobs are identical.
bool operator==(const WireCell::IBlob &lhs, const WireCell::IBlob &rhs)
{
    return lhs.ident() == rhs.ident() && lhs.cells().size() == rhs.cells().size();
}

/// Compare two blobs for inequality based on ident
bool operator<(const WireCell::IBlob& lhs, const WireCell::IBlob& rhs)
{
    if (lhs.ident() < rhs.ident()) {
	return true;
    }
    return lhs.cells().size() << rhs.cells().size();
}


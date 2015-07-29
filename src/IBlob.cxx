#include "WireCellIface/IBlob.h"

WireCell::IBlob::~IBlob()
{
}     

/// Return true if two blobs are identical.
bool operator==(const WireCell::IBlob &lhs, const WireCell::IBlob &rhs)
{
    return lhs.ident() == rhs.ident() && lhs.cells_size() == rhs.cells_size();
}

/// Compare two blobs for inequality based on ident
bool operator<(const WireCell::IBlob& lhs, const WireCell::IBlob& rhs)
{
    if (lhs.ident() == rhs.ident()) {
	return lhs.cells_size() << rhs.cells_size();
    }
    return lhs.ident() < rhs.ident();
}


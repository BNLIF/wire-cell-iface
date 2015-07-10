#ifndef WIRECELLIFACE_IBLOB
#define WIRECELLIFACE_IBLOB

#include "WireCellIface/ICell.h"

namespace WireCell {

    /// WireCell::IBlob - interface to information about a "blob" or
    /// an aggregation of cells.  A blob implements the cell
    /// interface.  This means that one may use a blob to hold other
    /// blobs.  When you construct IBlobs be mindful of using .ident()
    /// numbers which are degenerated with their ICell constituents.
    class IBlob : public ICell {
    public:
	virtual ~IBlob();

	/// Return the constituent ICells in this blob.
	virtual const CellVector& cells() const = 0;

    };

}

/// Return true if two blobs are identical.
bool operator==(const WireCell::IBlob &lhs, const WireCell::IBlob &rhs);

/// Compare two blobs for inequality based on ident
bool operator<(const WireCell::IBlob& lhs, const WireCell::IBlob& rhs);



#endif

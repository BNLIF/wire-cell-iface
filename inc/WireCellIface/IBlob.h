#ifndef WIRECELLIFACE_IBLOB
#define WIRECELLIFACE_IBLOB

#include "WireCellIface/ICell.h"

namespace WireCell {

    /** Interface to information about an aggregation of cells which
     * itself is a cell (implements WireCell::ICell interface).
     *
     * A blob is a cell which is composed of other Cells.  This means
     * that one may use a blob to hold other blobs, if warranted.
     *
     * When you construct IBlobs be mindful of using `.ident()`
     * numbers which are unique even among the individual ICell
     * constituents.
     */
    class IBlob : public ICell {
    public:
	virtual ~IBlob();

	/// Return a vector of individual cells.
	virtual ICell::vector cells() = 0;
    };

    
}

/// Return true if two blobs are identical.
bool operator==(const WireCell::IBlob &lhs, const WireCell::IBlob &rhs);

/// Compare two blobs for inequality based on ident
bool operator<(const WireCell::IBlob& lhs, const WireCell::IBlob& rhs);


#endif

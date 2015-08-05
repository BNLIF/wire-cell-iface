#ifndef WIRECELLIFACE_IBLOB
#define WIRECELLIFACE_IBLOB

#include "WireCellIface/ICell.h"

namespace WireCell {

    /** Interface to information about an aggregation of cells which
     * itself is a cell.
     *
     * A blob implements both the ICell and ICellSequence interfaces.
     * This means that one may use a blob to hold other blobs.
     *
     * When you construct IBlobs be mindful of using `.ident()`
     * numbers which are degenerated with their ICell constituents.
     */
    class IBlob : public ICell, public ICellSequence {
    public:
	virtual ~IBlob();

    };

    
    /// An abstract base class for anything that can sink a sequence
    /// of blobs.
    typedef ISink<IBlob> IBlobSink;
    
    /// An abstract base class for a sequence of blobs.
    typedef ISequence<IBlob> IBlobSequence;

}

/// Return true if two blobs are identical.
bool operator==(const WireCell::IBlob &lhs, const WireCell::IBlob &rhs);

/// Compare two blobs for inequality based on ident
bool operator<(const WireCell::IBlob& lhs, const WireCell::IBlob& rhs);


#endif

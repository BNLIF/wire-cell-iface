/**
 */

#ifndef WIRECELL_ICLUSTER
#define WIRECELL_ICLUSTER

#include "WireCellIface/IBlob.h"

namespace WireCell {

    class ICluster : public IBlobSet {
    public:
        virtual ~ICluster();
        
        /// The cluster is represented as a graph of IBlob nodes.  The
        /// set of all blobs is provided by IBlobSet and ICluster adds
        /// a collection of edges representing connectivity (by some
        /// definition) between a pair of blobs.  Edge directionality
        /// is not specified in this interface.
        typedef std::pair<IBlob::pointer, IBlob::pointer> edge_t;
        typedef std::vector<edge_t> edges_t;

        virtual edges_t edges() const = 0;

    };
}

#endif

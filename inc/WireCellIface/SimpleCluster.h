#include "WireCellIface/ICluster.h"
#include <boost/graph/copy.hpp>
namespace WireCell {

    class SimpleCluster : public ICluster {
    public:
        SimpleCluster(const cluster_graph_t& g) {
            boost::copy_graph(g, m_graph);
        }
        virtual ~SimpleCluster() { }
        const cluster_graph_t& graph() const { return m_graph; }

        // Non-const access for creators
        cluster_graph_t& graph() { return m_graph; }

    private:
        cluster_graph_t m_graph;
    };
}

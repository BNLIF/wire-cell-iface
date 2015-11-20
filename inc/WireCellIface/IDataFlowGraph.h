#ifndef WIRECELL_IDATAFLOWGRAPH
#define WIRECELL_IDATAFLOWGRAPH

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/INode.h"

namespace WireCell {

    /** Interface to a data flow processing graph. 
     * 
     * See also WireCell::IConnector and WireCell::IConnectorT.
     */
    class IDataFlowGraph : IComponent<IDataFlowGraph> {
    public:
	virtual ~IDataFlowGraph() {}

	/// Connect two nodes so that data runs from tail to head.
	/// Return false on error.
	virtual bool connect(INode::pointer tail, INode::pointer head,
			     int tail_port=0, int head_port=0) = 0;

	/// Run the graph, return false on error.
	virtual bool run() = 0;
    };

}

#endif

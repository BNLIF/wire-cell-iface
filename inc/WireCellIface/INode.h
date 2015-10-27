#ifndef WIRECELL_INODE
#define WIRECELL_INODE

#include "WireCellIface/IPort.h"

#include "WireCellUtil/IComponent.h"

#include <memory>
#include <vector>

namespace WireCell {

    /** A node is the ports associated with one computing unit.
     */ 
    class INode : public IComponent<INode> {
    public:
	virtual ~INode(){}

	typedef std::vector<IPort*> port_vector;

	virtual port_vector input_ports() const {
	    return port_vector();
	}
	virtual port_vector output_ports() const {
	    return port_vector();
	}
    };
}

#endif

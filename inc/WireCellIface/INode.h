#ifndef WIRECELL_INODE
#define WIRECELL_INODE

#include "WireCellIface/IPort.h"
#include <memory>

namespace WireCell {

    /** A node is the ports associated with one computing unit.
     */ 
    class INode {
    public:
	virtual ~INode(){}

	typedef std::shared_ptr<INode> pointer;

	virtual IPort::port_vector input_ports() const {
	    return IPort::port_vector();
	}
	virtual IPort::port_vector output_ports() const {
	    return IPort::port_vector();
	}
    };
}

#endif

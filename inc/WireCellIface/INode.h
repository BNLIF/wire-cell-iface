#ifndef WIRECELL_INODE
#define WIRECELL_INODE

#include "WireCellIface/IPort.h"

#include "WireCellUtil/IComponent.h"

#include <memory>
#include <vector>

namespace WireCell {

    /** A data flow node
     */ 
    class INode : public IComponent<INode> {
    public:
	virtual ~INode(){}

	// The signature is string unique to all classes that
	// implement a particular calling signature.  These should be
	// defined in lower level interfaces such as a mythical
	// IMyFooToBarConverter.
	virtual std::string signature() = 0;
	
	// Subclasses may override to provide the number of instances
	// that can run concurrently.  Default is 1.  Return 0 for
	// unlimited.  If the implementation buffers data between
	// calls to its signature it should likely return 1.
	virtual int concurrency() { return 1; }

    };
}

#endif

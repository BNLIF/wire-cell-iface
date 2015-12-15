#ifndef WIRECELL_INODE
#define WIRECELL_INODE

#include "WireCellUtil/IComponent.h"

#include <memory>
#include <vector>

namespace WireCell {

    /** A data flow node
     */ 
    class INode : public IComponent<INode> {
    public:
	virtual ~INode(){}

	enum NodeCategory {
	    unknown,
	    sourceNode,         // one pointer output
	    sinkNode,		// one pointer input
	    functionNode,       // one pointer input / output
	    queuedoutNode,	// one pointer input, queue of output
	    joinNode,		// tuple input, pointer output
	    splitNode,		// pointer input, tuple output
	    multioutNode,	// pointer input multi-queue output
	    hydraNode,		// multi-queue input and output
	};

	// Return the category type
	virtual NodeCategory category() = 0;

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

	// Return the names of the types this node takes as input.
	virtual std::vector<std::string> input_types() {
	    return std::vector<std::string> ();
	}
	// Return the names of the types this node takes as output.
	virtual std::vector<std::string>  output_types() {
	    return std::vector<std::string> ();
	}

    };
}


#endif

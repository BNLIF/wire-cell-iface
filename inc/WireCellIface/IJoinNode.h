#ifndef WIRECELL_IJOINNODE
#define WIRECELL_IJOINNODE

#include "WireCellIface/INode.h"

namespace WireCell {

    /** A node which joins N distinct data of the same point on
     * different ports and produces one instance of an output type
     * when some condition is met.
     */
    template <typename InputType, typename OutputType>
    class IJoinNode : public INode {
    public:
	typedef InputType input_type;
	typedef OutputType output_type;
	typedef std::shared_ptr<const InputType> input_pointer;
	typedef std::shared_ptr<const OutputType> output_pointer;

	virtual ~IJoinNode() {}

	virtual bool insert(const input_pointer& in, int port) = 0;
	virtual bool extract(output_pointer& out) = 0;

	/// determine how many input ports the node requires.
	virtual int ninputs() = 0;

	// Return the names of the types this node takes as input.
	virtual std::vector<std::string>  input_types() {
	    std::string n = typeid(input_type).name();
	    std::vector<std::string> ret;
	    for (int ind=0; ind<ninputs(); ++ind) {
		ret.push_back(n);
	    }
	    return ret;
	}
	// Return the names of the types this node produces as output.
	virtual std::vector<std::string>  output_types() {
	    return std::vector<std::string>{typeid(output_type).name()};
	}
	
    };
    
}

#endif

#ifndef WIRECELL_ISINKNODE
#define WIRECELL_ISINKNODE

#include "WireCellIface/INode.h"

namespace WireCell {

    /** A node which acts as a sink.
     */
    template <typename InputType>
    class ISinkNode : public INode
    {
    public:
	typedef InputType input_type;
	typedef std::shared_ptr<const InputType> input_pointer;

	virtual ~ISinkNode() {}

	/// The calling signature:
	virtual bool insert(const input_pointer& in) = 0;

	// Return the names of the types this node takes as input.
	virtual std::vector<std::string>  input_types() {
	    return std::vector<std::string>{typeid(input_type).name()};
	}

    };

}

#endif

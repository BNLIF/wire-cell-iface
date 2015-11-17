#ifndef WIRECELL_IFUNCTIONNODE
#define WIRECELL_IFUNCTIONNODE

#include "WireCellIface/INode.h"

namespace WireCell {

    /** A node which acts as a stateless function.
     */
    template <typename InputType, typename OutputType>
    class IFunctionNode : public INode
    {
    public:
	typedef InputType input_type;
	typedef OutputType output_type;
	typedef std::shared_ptr<const InputType> input_pointer;
	typedef std::shared_ptr<const OutputType> output_pointer;

	virtual ~IFunctionNode() {}

	/// The calling signature:
	virtual bool operator()(const input_pointer& in, output_pointer& out) = 0;


	/// By default assume all subclasses are stateless.
	virtual int concurrency() { return 0; }

	// Return the names of the types this node takes as input.
	virtual std::vector<std::string>  input_types() {
	    return std::vector<std::string>{typeid(input_type).name()};
	}
	// Return the names of the types this node produces as output.
	virtual std::vector<std::string>  output_types() {
	    return std::vector<std::string>{typeid(output_type).name()};
	}

    };

}

#endif

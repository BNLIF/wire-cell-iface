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
	typedef IFunctionNode<InputType,OutputType> signature_type;
	typedef std::shared_ptr<const InputType> input_pointer;
	typedef std::shared_ptr<const OutputType> output_pointer;

	virtual ~IFunctionNode() {}

	/// Set the signature for all subclasses.  
	virtual std::string signature() {
	    return typeid(signature_type).name();
	}

	/// The calling signature:
	virtual bool operator()(const input_pointer& in, output_pointer& out) = 0;


	/// By default assume all subclasses are stateless.
	virtual int concurrency() { return 0; }

    };

}

#endif

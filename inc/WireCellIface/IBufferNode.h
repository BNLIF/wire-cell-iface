#ifndef WIRECELL_IBUFFERNODE
#define WIRECELL_IBUFFERNODE

#include "WireCellIface/INode.h"

namespace WireCell {

    /** A node which acts as a stateful buffer.
     */
    template <typename InputType, typename OutputType>
    class IBufferNode : public INode
    {
    public:
	typedef InputType input_type;
	typedef OutputType output_type;
	typedef IBufferNode<InputType,OutputType> signature_type;
	typedef std::shared_ptr<const InputType> input_pointer;
	typedef std::shared_ptr<const OutputType> output_pointer;

	virtual ~IBufferNode() {}

	/// Set the signature for all subclasses.  
	virtual std::string signature() {
	    return typeid(signature_type).name();
	}

	/// The calling signature:
	virtual bool insert(const input_pointer& in) = 0;
	virtual bool extract(output_pointer& out) = 0;


    };

}

#endif

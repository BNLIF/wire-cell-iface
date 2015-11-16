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
	typedef ISinkNode<InputType> signature_type;
	typedef std::shared_ptr<const InputType> input_pointer;

	virtual ~ISinkNode() {}

	/// Set the signature for all subclasses.  
	virtual std::string signature() {
	    return typeid(signature_type).name();
	}

	/// The calling signature:
	virtual bool insert(const input_pointer& in) = 0;


    };

}

#endif

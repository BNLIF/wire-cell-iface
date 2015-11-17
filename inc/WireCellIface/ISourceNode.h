#ifndef WIRECELL_ISOURCENODE
#define WIRECELL_ISOURCENODE

#include "WireCellIface/INode.h"

namespace WireCell {

    /** A node which acts as a source.
     */
    template <typename OutputType>
    class ISourceNode : public INode
    {
    public:
	typedef OutputType output_type;
	typedef ISourceNode<OutputType> signature_type;
	typedef std::shared_ptr<const OutputType> output_pointer;

	virtual ~ISourceNode() {}

	/// Set the signature for all subclasses.
	virtual std::string signature() {
	   return typeid(signature_type).name();
	}

	/// The calling signature:
	virtual bool extract(output_pointer& out) = 0;

	// Return the names of the types this node takes as output.
	virtual std::vector<std::string>  output_types() {
	    return std::vector<std::string>{typeid(output_type).name()};
	}

    };

}

#endif

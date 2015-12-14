#ifndef WIRECELL_IBUFFERNODE
#define WIRECELL_IBUFFERNODE

#include "WireCellIface/INode.h"

#include <boost/any.hpp>

namespace WireCell {

    /** A node which acts as a stateful buffer.
     */
    class IBufferNodeBase : public INode
    {
    public:
	typedef std::shared_ptr<IBufferNodeBase> pointer;

	virtual ~IBufferNodeBase() {}

	virtual NodeCategory category() {
	    return multioutNode;
	}

	virtual bool insert(const boost::any& in) = 0;
	virtual bool extract(boost::any& anyout)=0;
    };

    template <typename InputType, typename OutputType>
    class IBufferNode : public IBufferNodeBase
    {
    public:
	typedef InputType input_type;
	typedef OutputType output_type;
	typedef std::shared_ptr<const InputType> input_pointer;
	typedef std::shared_ptr<const OutputType> output_pointer;

	virtual ~IBufferNode() {}

	virtual bool insert(const boost::any& anyin){
	    input_pointer in = boost::any_cast<input_pointer>(anyin);
	    return this->insert(in);
	}
	virtual bool extract(boost::any& anyout){
	    output_pointer out;
	    bool ok = this->extract(out);
	    if (!ok) return false;
	    anyout = out;
	    return true;
	}

	/// The calling signature:
	virtual bool insert(const input_pointer& in) = 0;
	virtual bool extract(output_pointer& out) = 0;


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

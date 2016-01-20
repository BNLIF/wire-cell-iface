/** A hydra is a node with N inputs receiving synchronous input and
 * producing M asynchronous outputs.  It is like a join node
 * on input and multiple queued nodes on output.
 */

#ifndef WIRECELL_IHYDRANODE
#define WIRECELL_IHYDRANODE

#include "WireCellIface/INode.h"
#include "WireCellUtil/TupleHelpers.h"

#include <boost/any.hpp>
#include <vector>
#include <deque>

namespace WireCell {


    /** Base hydra node class.
     *
     * An interface to a callable taking a vector of input objects and
     * a vector of output queues.
     */ 
    class IHydraNodeBase : public INode
    {
    public:
	typedef std::shared_ptr<IHydraNodeBase> pointer;

	virtual ~IHydraNodeBase() {}

	typedef std::vector<boost::any> any_vector;
	typedef std::deque<boost::any> any_queue;
	typedef std::vector< any_queue > any_queue_vector

	/// The calling signature:
	virtual bool operator()(const any_vector& anyin, any_queue_vector& anyoutq) = 0;

	virtual NodeCategory category() {
	    return hydraNode;
	}

	/// By default assume hydra nodes can do their thing stateless.
	virtual int concurrency() { return 0; }


    };

    /** A hydra with input and output fixed at compile-time with tuples.
     */
    template <typename InputTuple, typename OutputTuple>
    class IHydraNode : public IHydraNodeBase {
    public:

	typedef InputTuple input_tuple_type;
	typedef OutputTuple output_tuple_type;

	typedef tuple_helper<InputTuple> input_helper_type;
	typedef tuple_helper<OutputTuple> output_helper_type;
	typedef typename output_helper_type::queued_tuple_type output_queues_type;

	virtual ~IHydraNode() {}

	/// Translate call from any to types and back.
	virtual bool operator()(const any_vector& anyin, any_queue_vector& anyoutq) {
	    input_helper_type ih;
	    output_helper_type oh;

	    auto intup = ih.from_any(anyin);
	    output_queues_type outq;

	    bool ok = (*this)(intup, outq);
	    if (ok) {
		anyout = oh.as_any_queue(outq);
	    }
	    return ok;
	}

	/// Typed interface for subclass to implement.
	virtual bool operator()(const input_tuple_type& intup, output_queues_type& outqs) = 0;

	// Return the names of the types this node takes as input.
	virtual std::vector<std::string>  input_types() {
	    input_helper_type ih;
	    return ih.type_names();
	}
	// Return the names of the types this node produces as output.
	virtual std::vector<std::string>  output_types() {
	    output_helper_type oh;
	    return oh.type_names();
	}
	
    };
    
}

#endif

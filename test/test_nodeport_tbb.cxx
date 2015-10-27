#include <tbb/flow_graph.h>
#include <iostream>
#include <tuple>

#include "PortsAndNodes.h"

#include "WireCellUtil/Testing.h"

using namespace std;
namespace dfp = tbb::flow;


template<typename DataType>
struct source_body_adapter {
    typedef DataType data_type;
    typedef std::shared_ptr<const data_type> data_pointer;
    typedef ISending<DataType> port_type;

    port_type* port;
    source_body_adapter(INode& node) {
	port = dynamic_cast<port_type*>(node.output_ports()[0]);
    }

    bool operator()(data_pointer& out) {
	if (port->extract(out)) {
	    if (!out) {
		cerr << "source EOS" << endl;
		return true; 
	    }
	    cerr << "Extracted " << *out << endl;
	    return true;
	}
	cerr << "Failed to extract" << endl;
	return false;
    }
};


// template<typename DataType>
// struct sink_body_adapter {
//     typedef DataType data_type;
//     typedef std::shared_ptr<const data_type> data_pointer;
//     typedef IPortInputT<DataType> port_type;
//     typedef std::shared_ptr<port_type> port_pointer;

//     port_pointer port;
//     sink_body_adpater(INode& node) {
// 	port = dynamic_pointer_cast<port_type>(node.input_ports()[0]);
//     }
    
//     data_poiner operator()(data_pointer& in) {
// 	if (port->insert(in)) {
// 	    cerr << "Inserted " << in << endl;
// 	    return true;
// 	}
// 	cerr << "Failed to insert " << in << endl;
// 	return false;
//     }
// };

template<typename InputType, typename OutputType>
struct function_body_adapter {
    // input
    typedef InputType input_data_type;
    typedef std::shared_ptr<const input_data_type> input_data_pointer;
    typedef IReceiving<InputType> input_port_type;

    // output
    typedef OutputType output_data_type;
    typedef std::shared_ptr<const output_data_type> output_data_pointer;
    typedef ISending<OutputType> output_port_type;

    input_port_type* input_port;
    output_port_type* output_port;
    function_body_adapter(INode& node) {
	input_port = dynamic_cast<input_port_type*>(node.input_ports()[0]);
	output_port = dynamic_cast<output_port_type*>(node.output_ports()[0]);
    }

    output_data_pointer operator()(const input_data_pointer& in) {
	if (!in) {
	    cerr << "EOS on input" << endl;
	    return nullptr;
	}
	if (input_port->insert(in)) {
	    cerr << "Inserted " << *in << endl;
	}
	else {
	    cerr << "Failed to insert" << endl;
	    return nullptr;	// fixme: move to malfunction
	}
	output_data_pointer out;
	if (output_port->extract(out)) {
	    if (!out) {
		cerr << "EOS on output" << endl;
		return nullptr;
	    }
	    cerr << "Extracted " << *out << endl;
	    return out;
	}
	cerr << "Failed to extract after " << *in << endl;
	return nullptr;
    }

};

int main() {

    dfp::graph graph;
    std::vector<int> numbers{5,4,3,2,1,0};

    TestSourceNode source(numbers);
    TestConverterNode* pconverter = new TestConverterNode;
    TestConverterNode& converter = *pconverter;
    //TestSinkNode sink;

    INode::pointer node_ptr(pconverter);
    Assert(node_ptr);
    ITestConverter::pointer tc_ptr = dynamic_pointer_cast<ITestConverter>(node_ptr);
    Assert(tc_ptr);
    IConfigurable::pointer cfg_ptr = dynamic_pointer_cast<IConfigurable>(node_ptr);
    Assert(cfg_ptr);
    auto cfg = cfg_ptr->default_configuration();
    cerr << "Default config: " << cfg << endl;
    


    typedef std::shared_ptr<const int> int_pointer;
    typedef std::shared_ptr<const float> float_pointer;

    dfp::source_node<int_pointer> source_node(graph, source_body_adapter<int>(source));

    dfp::function_node<int_pointer, float_pointer> converter_node(graph, 1, function_body_adapter<int,float>(converter));

    //dfp::function_node<TestSourceNode::poiner> sink_node(graph, sink_body_adapter<int>(sink
    

    // dfp::source_node<int> number_source_node(g, number_source<int>(numbers), false);
    // dfp::function_node<int, int> int_chirp_node(g, dfp::unlimited, [](const int &v) {
    // 	    cerr << "i value: " << v << endl;
    // 	    msleep(v*100);
    // 	    cerr << "...woke, returning i=" << v << endl;
    // 	    return v;
    // 	});
    // dfp::function_node<float,float> float_chirp_node(g, dfp::unlimited, [](const float &v) {
    // 	    cerr << "f value: " << v << endl;
    // 	    msleep(v*100);
    // 	    cerr << "...woke, returning f=" << v << endl;
    // 	    return v;
    // 	});
    // int2float_node i2fcaster_node(g, dfp::unlimited, I2Fcaster());
    
    cerr << "make edges" << endl;
    make_edge(source_node, converter_node);
    // make_edge(int_chirp_node, i2fcaster_node);
    // make_edge(dfp::output_port<0>(i2fcaster_node), float_chirp_node);

    cerr << "Activate source" << endl;
    source_node.activate();
    cerr << "Waiting for graph" << endl;
    graph.wait_for_all();
    return 0;
}

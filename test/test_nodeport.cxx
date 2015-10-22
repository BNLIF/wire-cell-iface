#include "WireCellUtil/Testing.h"

#include "PortsAndNodes.h"

#include <iostream>
#include <cmath>

using namespace WireCell;
using namespace std;


// fixme: add test of converter pattern
// fixme: add test of connector pattern

void test_simple_port_action() {
    TestSenderPort<int> sp(42);
    TestReceiverPort<int> rp;
    shared_ptr<const int> dat = make_shared<const int>(0);
    
    Assert(sp.extract(dat));
    Assert(*dat == 42);
    Assert(rp.insert(dat));

    Assert(sp.extract(dat));
    Assert(!dat);
    Assert(rp.insert(dat));

    cerr << "Next line should give error" << endl;
    Assert(!sp.extract(dat));
    cerr << "Next line should give error" << endl;
    Assert(!rp.insert(dat));
}

void test_simple_source_node_action() {
    vector<int> datastream = {5,4,3,2,1,0};
    TestSourceNode source(datastream);
    shared_ptr<const int> dat = make_shared<const int>(99);

    Assert(source.input_ports().empty());
    Assert(source.output_ports().size() == 1);
    IPort::pointer port = source.output_ports()[0];
    Assert(port);

    // concrete execution model works at the typed level
    typedef IPortOutputT<int> output_port_type;
    typedef shared_ptr<output_port_type> output_port_pointer;

    output_port_pointer oport = dynamic_pointer_cast< output_port_type >(port);
    Assert(oport);

    while (*dat > 0) {
	Assert(oport->extract(dat));
	Assert(*dat >= 0);
    }
    Assert(oport->extract(dat));
    Assert(!dat);		// eos
    
    Assert(!oport->extract(dat));// should fail
}

void test_simple_sink_node_action() {
    vector<float> datastream = {5,4,3,2,1,0};
    TestSinkNode sink;

    Assert(sink.output_ports().empty());
    Assert(sink.input_ports().size() == 1);
    IPort::pointer port = sink.input_ports()[0];
    Assert(port);

    // concrete execution model works at the typed level
    typedef IPortInputT<float> input_port_type;
    typedef shared_ptr<input_port_type> input_port_pointer;
    input_port_pointer iport = dynamic_pointer_cast< input_port_type >(port);
    Assert(iport);

    for (float num : datastream) {
	shared_ptr<const float> dat = make_shared<const float>(num);
	Assert(iport->insert(dat));
    }
    Assert(iport->insert(nullptr));  // EOS
    Assert(!iport->insert(nullptr)); // past EOS

}

void test_simple_converter_node_action() {
    vector<int> datastream = {5,4,3,2,1,0};
    TestConverterNode converter;

    Assert(converter.input_ports().size() == 1);
    Assert(converter.output_ports().size() == 1);
    IPort::pointer iport = converter.input_ports()[0];
    IPort::pointer oport = converter.output_ports()[0];
    Assert(iport);
    Assert(oport);

    // concrete execution model works at the typed level
    typedef IPortInputT<int> input_port_type;
    typedef shared_ptr<input_port_type> input_port_pointer;
    typedef IPortOutputT<float> output_port_type;
    typedef shared_ptr<output_port_type> output_port_pointer;

    input_port_pointer itport = dynamic_pointer_cast< input_port_type >(iport);
    Assert(itport);
    output_port_pointer otport = dynamic_pointer_cast< output_port_type >(oport);
    Assert(otport);

    // synchronous
    for (int num : datastream) {
	shared_ptr<const int> dat1 = make_shared<const int>(num);
	Assert(itport->insert(dat1));
	shared_ptr<const float> dat2 = make_shared<const float>(-1);
	Assert(otport->extract(dat2));
	double diff = *dat1 - *dat2;
	Assert(std::abs(diff) < 1e-9);
	cerr << "TestConverterNode: <-- " << *dat1 << " --> " << *dat2 << endl;
    }

    // pump and dump
    for (int num : datastream) {
	shared_ptr<const int> dat1 = make_shared<const int>(num);
	Assert(itport->insert(dat1));
	cerr << "TestConverterNode: <-- " << *dat1 << endl;
    }
    vector<float> output;
    for (int num : datastream) { // just use as a count
	shared_ptr<const float> dat2 = make_shared<const float>(-1);
	Assert(otport->extract(dat2));
	output.push_back(*dat2);
	cerr << "TestConverterNode: --> " << *dat2 << endl;
    }
    Assert(output.size() == datastream.size());

}

int main()
{
    test_simple_port_action();
    test_simple_source_node_action();
    test_simple_sink_node_action();
    test_simple_converter_node_action();
    return 0;
}

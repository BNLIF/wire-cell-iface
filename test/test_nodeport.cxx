#include "WireCellIface/IPort.h"
#include "WireCellIface/INode.h"
#include "WireCellUtil/Testing.h"

#include <iostream>
#include <deque>
#include <cmath>

using namespace WireCell;
using namespace std;

// This little port first generates a single value, then returns EOS
// and then throws errors.
template<typename DataType>
class TestSenderPort : public IPortOutputT<DataType>
{
public:
    typedef shared_ptr<const DataType> pointer;

    TestSenderPort(const DataType& val)
	: m_val(make_shared<DataType>(val))
	, m_ncalled(-1) {}
    virtual ~TestSenderPort() {}

    virtual bool extract(pointer& out) {
	++m_ncalled;
	if (!m_ncalled) {	// first time
	    out = m_val;	// give val
	    cerr << "TestSenderPort -> " << *out << endl;
	    return true;
	}
	if (m_ncalled == 1) {	// second time
	    out = nullptr;	// EOS
	    cerr << "TestSenderPort -> EOS" << endl;
	    return true;
	}
	cerr << "TestSenderPort: ERROR: past EOS" << endl;
	return false;
    }
private:
    pointer m_val;
    int m_ncalled;
};

template<typename DataType>
class TestReceiverPort : public IPortInputT<DataType>
{
public:
    typedef shared_ptr<const DataType> pointer;

    TestReceiverPort()
	: m_val()
	, m_ncalled(-1) {}
    virtual ~TestReceiverPort() {}

    virtual bool insert(const pointer& in) {
	++m_ncalled;
	if (!m_ncalled) {	// first time
	    m_val = in;		// accept val
	    cerr << "TestReceiverPort <- " << *in << endl;
	    return true;
	}
	if (m_ncalled == 1) {	// second time
				// don't clobber m_val
	    cerr << "TestReceiverPort <- EOS" << endl;
	    return true;	// EOS
	}
	cerr << "TestReceiverPort: ERROR: past EOS" << endl;
	return false;
    }
private:
    pointer m_val;
    int m_ncalled;
};

/// nodes ///

class TestSourceNode : public INode
{
private:
    typedef shared_ptr<const int> pointer;

    /// a private class providing the one and only port
    class TSNPort : public IPortOutputT<int> {
	TestSourceNode* m_node;
	bool m_eos;
    public:
	TSNPort(TestSourceNode* tsn) : m_node(tsn), m_eos(false) {}
	virtual bool extract(shared_ptr<const int>& out) {
	    if (m_eos) { return false; }
	    if (m_node->empty()) {
		m_eos = true;
		out = nullptr;
		return true;
	    }
	    int dat = 0;
	    bool ok = m_node->next(dat);
	    if (!ok) { return false; }
	    out = make_shared<const int>(dat);
	    return true;	    
	}
    };

    IPort::port_vector m_ports;
    std::vector<int> m_data;    

public:

    TestSourceNode(const std::vector<int>& data)
	: m_data(data)
    {
	m_ports.push_back(make_shared<TSNPort>(this));	    
    }
    virtual ~TestSourceNode() {}
    virtual IPort::port_vector output_ports() const {
	return m_ports;
    }

    bool next(int& out) {
	if (empty()) {
	    cerr << "TestSourceNode: EOS" << endl;
	    return false;
	}
	out = m_data.front();
	m_data.erase(m_data.begin());
	cerr << "TestSourceNode: " << out
	     << " with " << m_data.size() << " left" << endl;
	return true;
    }
    bool empty() const { return m_data.empty(); }
};

class TestSinkNode : public INode
{
private:

    class TSNPort : public IPortInputT<float> {
	TestSinkNode* m_node;
	bool m_eos;
    public:
	TSNPort(TestSinkNode* tsn) : m_node(tsn), m_eos(false) {}
	virtual bool insert(const shared_ptr<const float>& in) {
	    if (m_eos) { return false; }
	    if (!in) { m_eos = true; return true; }
	    return m_node->give(*in);
	}
    };

    IPort::port_vector m_ports;
    std::vector<float> m_data;    

public:
    TestSinkNode() {
	m_ports.push_back(make_shared<TSNPort>(this));
    }
    virtual ~TestSinkNode() {}
    virtual IPort::port_vector input_ports() const {
	return m_ports;
    }

    bool give(const int& dat) {
	m_data.push_back(dat);
	cerr << "TestSinkNode: give("<<dat<<") have " << m_data.size() << endl;
	return true;
    }
    vector<float> data() const  { return m_data; }
};


class TestConverterNode : public INode
{
private:

    class OutPort : public IPortOutputT<float> {
	deque<float> m_data;
    public:
	virtual ~OutPort() {}
	virtual bool extract(shared_ptr<const float>& out) {
	    if (m_data.empty()) { return false; }
	    float dat = m_data.front();
	    m_data.pop_front();
	    out = make_shared<const float>(dat);
	    return true;
	}
	void give(float dat) { m_data.push_back(dat); }
    };

    class InPort : public IPortInputT<int> {
	shared_ptr<OutPort> m_out;
    public:
	InPort(shared_ptr<OutPort> out) : m_out(out) {}
	virtual bool insert(const shared_ptr<const int>& in) {
	    if (!in) { return true; }
	    m_out->give(*in);
	    return true;
	}
    };

    
    IPort::port_vector m_input_ports, m_output_ports;

public:
    TestConverterNode() {
	auto op = make_shared<OutPort>();
	auto ip = make_shared<InPort>(op);
	m_input_ports.push_back(ip);
	m_output_ports.push_back(op);
    }
    virtual IPort::port_vector input_ports() const {
	return m_input_ports;
    }
    virtual IPort::port_vector output_ports() const {
	return m_output_ports;
    }
};


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

    Assert(!sp.extract(dat));
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

#ifndef WIRECELL_TEST_PORTSANDNODES
#define WIRECELL_TEST_PORTSANDNODES

#include "WireCellIface/IPort.h"
#include "WireCellIface/INode.h"

#include <deque>
#include <iostream>

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

    typedef shared_ptr<const int> pointer;

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

#endif 

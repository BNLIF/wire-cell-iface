#ifndef WIRECELL_TEST_PORTSANDNODES
#define WIRECELL_TEST_PORTSANDNODES

#include "WireCellIface/SimpleNodes.h"
#include "WireCellIface/IConfigurable.h"

#include <deque>
#include <iostream>

using namespace WireCell;
using namespace std;

// This little port first generates a single value, then returns EOS
// and then throws errors.
template<typename DataType>
class TestSenderPort : public ISending<DataType>
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
class TestReceiverPort : public IReceiving<DataType>
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




class TestSourceNode : public ISendingNode<int>
{
    std::vector<int> m_data;
    bool m_eos;
public:

    TestSourceNode(const std::vector<int>& data)
	: m_data(data)
	, m_eos(false)
    {
    }
    virtual ~TestSourceNode() {}
    
    virtual bool extract(output_pointer& out) {
	if (m_eos) {
	    cerr << "TestSourceNode: ERROR: past EOS" << endl;
	    return false;
	}
	if (m_data.empty()) {
	    m_eos = true;
	    out = nullptr;
	    cerr << "TestSourceNode: hit EOS" << endl;
	    return true;
	}
	int num = m_data.front();
	m_data.erase(m_data.begin());
	out = make_shared<const int>(num);
	cerr << "TestSourceNode: " << num
	     << " with " << m_data.size() << " left" << endl;
	return true;
    }
};

class TestSinkNode : public IReceivingNode<float>
{
private:

    std::vector<float> m_data;    
    bool m_eos;

public:
    TestSinkNode() : m_eos(false) {}
    virtual ~TestSinkNode() {}

    virtual bool insert(const input_pointer& in) {
	if (m_eos) {
	    cerr << "TestSinkNode: ERROR: past EOS" << endl;
	    return false;
	}
	if (!in) {
	    m_eos = true;
	    cerr << "TestSinkNode: hit EOS" << endl;
	    return true;
	}
	m_data.push_back(*in);
	cerr << "TestSinkNode: with ("<<in<<") have " << m_data.size() << endl;
	return true;
    }
    vector<float> data() const  { return m_data; }
};


class ITestConverter : public IComponent<ITestConverter>
		     , public IConverterNode<int, float>
{
public:
    typedef std::shared_ptr<ITestConverter> pointer;
    virtual ~ITestConverter() {};
};

class TestConverterNode : public ITestConverter, public IConfigurable
{
    deque<float> m_data;
public:

    virtual ~TestConverterNode() {}

    virtual void configure(const WireCell::Configuration& config) {
	cerr << "Configured with " << config << endl;
    }

    virtual bool extract(output_pointer& out) {
	if (m_data.empty()) { return false; }
	float dat = m_data.front();
	m_data.pop_front();
	out = make_shared<const float>(dat);
	return true;
    }
    virtual bool insert(const input_pointer& in) {
	if (!in) { return true; }
	m_data.push_back(*in);
	return true;
    }

};

#endif 

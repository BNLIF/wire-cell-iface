#include "WireCellIface/IConnector.h"
#include "WireCellUtil/Testing.h"

#include <iostream>

using namespace WireCell;
using namespace std;

template<typename PortType>
class TestSender : public ISendingT<PortType>
{
public:

    typedef typename IPortT<PortType>::port_pointer port_pointer;

    TestSender(const PortType& val)
	: m_val(port_pointer(new PortType(val)))
	, m_ncalled(-1) {}
    virtual ~TestSender() {}

    virtual bool extract(port_pointer& out) {
	++m_ncalled;
	if (!m_ncalled) {	// first time
	    out = m_val;	// give val
	    cerr << "TestSender -> " << *out << endl;
	    return true;
	}
	if (m_ncalled == 1) {	// second time
	    out = nullptr;	// EOS
	    cerr << "TestSender -> EOS" << endl;
	    return true;
	}
	cerr << "TestSender: ERROR" << endl;
	return false;		// read past EOS
    }

private:
    port_pointer m_val;
    int m_ncalled;
};

template<typename PortType>
class TestReceiver : public IReceivingT<PortType>
{
public:

    typedef typename IPortT<PortType>::port_pointer port_pointer;

    TestReceiver()
	: m_val()
	, m_ncalled(-1) {}
    virtual ~TestReceiver() {}

    virtual bool insert(const port_pointer& in) {
	++m_ncalled;
	if (!m_ncalled) {	// first time
	    m_val = in;		// accept val
	    cerr << "TestReceiver <- " << *in << endl;
	    return true;
	}
	if (m_ncalled == 1) {	// second time
				// don't clobber m_val
	    cerr << "TestReceiver <- EOS" << endl;
	    return true;	// EOS
	}
	cerr << "TestReceiver: ERROR" << endl;
	return false;		// write past EOS
    }

private:
    port_pointer m_val;
    int m_ncalled;
};


template<typename PortType>
class TestConnector : public Connector<PortType>
{
public:

    typedef typename Connector<PortType>::sending_pointer sending_pointer;
    typedef typename Connector<PortType>::receiving_pointer receiving_pointer;
    typedef typename IPortT<PortType>::port_pointer port_pointer;

    //TestConnector() : Connector<PortType>() {}

    virtual ~TestConnector() {}

    /** for this test the connect is an immediate transfer of data,
     * which is NOT what should be done for a "real" DFP.  A real DFP
     * should call whatever form of make_edge(s,r) that the DFP engine
     * provides.
     */
    virtual bool connect(sending_pointer& sender,
			 receiving_pointer& receiver) {
	port_pointer dat;
	if (!sender->extract(dat)) { return false;}
	if (!receiver->insert(dat)) { return false;}
	cerr << "TestConnector: OKAY" << endl;
	return true;
    }

};

int main()
{
    // This is for side effect of registering and normally should be
    // done by the component providing the execution model.  There
    // they might be held in IConnector::pointer objects.  Here it
    // looks like we leak them but they are stored in a lookup in the
    // base class as a side-effect
    new TestConnector<int>;
    new TestConnector<float>;
    new TestConnector<double>;

    // This simulates NamedFactory lookups + applying Configuration for
    // processing nodes.
    ISending::pointer send_i = ISending::pointer(new TestSender<int>(42));
    ISending::pointer send_f = ISending::pointer(new TestSender<float>(6.9));
    ISending::pointer send_d = ISending::pointer(new TestSender<double>(137.0));
    IReceiving::pointer recv_i = IReceiving::pointer(new TestReceiver<int>);
    IReceiving::pointer recv_f = IReceiving::pointer(new TestReceiver<float>);
    IReceiving::pointer recv_d = IReceiving::pointer(new TestReceiver<double>);

    
    IConnector::pointer con_i = connector_lookup(*send_i);
    IConnector::pointer con_f = connector_lookup(*send_f);
    IConnector::pointer con_d = connector_lookup(*send_d);

    Assert(con_i && con_f && con_d);

    Assert(con_i->connect(send_i, recv_i));
    Assert(con_f->connect(send_f, recv_f));
    Assert(con_d->connect(send_d, recv_d));

    Assert(!con_i->connect(send_i, recv_f));
    Assert(!con_i->connect(send_f, recv_f));

    return 0;
}

#ifndef WIRECELL_RECEIVINGPORT
#define WIRECELL_RECEIVINGPORT

#include <memory>

namespace WireCell {

    /** Adapt an IReceiving<DataType> to a port.
     */
    template <typename DataType>
    class ReceivingPort : public IPortInputT<DataType> {
    public:
	
	typedef std::shared_ptr<DataType> pointer;
	typedef std::shared_ptr< IReceiving<DataType> > receiving_ptr

	ReceivingPort(receivin_ptr receiver) : m_receiver(receiver) { }
	virtual ~ReceivingPort() {}

	virtual bool insert(pointer& out) {
	    if (!m_receiver) { return false; }
	    return m_receiver->extract(out);
	}
    private:
	pointer m_receiver;
    };

}

#endif

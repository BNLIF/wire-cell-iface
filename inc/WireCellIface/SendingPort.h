#ifndef WIRECELL_SENDINGPORT
#define WIRECELL_SENDINGPORT

#include <memory>

namespace WireCell {

    /** Adapt an ISending<DataType> to a port.
     */
    template <typename DataType>
    class SendingPort : public IPortInputT<DataType> {
    public:
	
	typedef std::shared_ptr<DataType> pointer;
	typedef std::shared_ptr< ISending<DataType> > sending_ptr

	SendingPort(sending_ptr sender) : m_sender(sender) { }
	virtual ~SendingPort() {}

	virtual bool insert(const pointer& in) {
	    if (!m_sender) { return false; }
	    return m_sender->insert(in);
	}
    private:
	pointer m_sender;
    };

}

#endif

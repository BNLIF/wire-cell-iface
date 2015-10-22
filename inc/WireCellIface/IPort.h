#ifndef WIRECELL_IPORT
#define WIRECELL_IPORT

#include <memory>

namespace WireCell {

    /** A port embodies the connection point between a node and the
     * abstract execution model for a given type of data.  A node may
     * have zero or more input and output ports.  A base port must
     * provide the data type name as a string.  See `WireCell::IPortT`.
     */
    class IPort {
    public:
	virtual ~IPort() {}

	/** Subclass must provide.  If implementation is a class
	 * templated on T, the body is probably simply:
	 *
	 * ```
	 * return typeid(T).name();
	 * ```
	 */
	virtual std::string port_type_name() const = 0;

	virtual IPort* port() const = 0;
    };

    /** A templated Port providing a port `port_type_name` based on
     * the typeid of the templated type.
     */
    template<typename DataType>
    class IPortT : public IPort {
    public:
	virtual ~IPortT() {}

	typedef DataType data_type;
	typedef std::shared_ptr<const data_type> data_pointer;
	typedef IPortT<DataType> port_type;
	typedef std::shared_ptr<port_type> port_pointer;

	virtual std::string port_type_name() const {
	    return typeid(data_type).name();
	}

	// convenience downcast
	virtual IPort* port() const { return (IPort*)this; }

    };

    /** An input port to work with an IConnectorT connector. */
    template<typename DataType>
    class IReceiving : public IPortT<DataType> {
    public:
	virtual ~IReceiving() {}

	typedef typename IPortT<DataType>::data_pointer input_pointer;

	/// Subclass implements to potentially receive new data.
	virtual bool insert(const input_pointer& in) = 0;

    };

    /** An output port to work with an IConnectorT connector. */
    template<typename DataType>
    class ISending : public IPortT<DataType> {
    public:
	virtual ~ISending() {}

	typedef typename IPortT<DataType>::data_pointer output_pointer;

	/// Subclass implements to potentially provide new data.
	virtual bool extract(output_pointer& in) = 0;
    };

}

#endif

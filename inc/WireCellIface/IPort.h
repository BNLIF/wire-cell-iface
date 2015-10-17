#ifndef WIRECELL_IPORT
#define WIRECELL_IPORT

#include <memory>
#include <vector>

namespace WireCell {

    /** A port embodies the connection point between a node and the
     * abstract execution model for a given type of data.  A node may
     * have zero or more input and output ports.  A base port must
     * provide the data type name as a string.  See `WireCell::IPortT`.
     */
    class IPort {
    public:
	virtual ~IPort() {}

	typedef std::shared_ptr<IPort> pointer;
	typedef std::vector<pointer> port_vector;

	/** Subclass must provide.  If implementation is a class
	 * templated on T, the body is probably simply:
	 *
	 * ```
	 * return typeid(T).name();
	 * ```
	 */
	virtual std::string port_type_name() const = 0;
    };

    /** A templated Port providing a port `port_type_name` based on
     * the typeid of the templated type.
     */
    template<typename PortType>
    class IPortT : virtual public IPort {
    public:
	virtual ~IPortT() {}

	typedef PortType port_type;

	virtual std::string port_type_name() const {
	    return typeid(port_type).name();
	}
    };

    /** An input port to work with an IConnectorT connector. */
    template<typename PortType>
    class IPortInputT : virtual public IPortT<PortType> {
    public:
	virtual ~IPortInputT() {}

	typedef std::shared_ptr<const PortType> pointer;

	/// Subclass implements to potentially receive new data.
	virtual bool insert(const pointer& in) = 0;

    };

    /** An output port to work with an IConnectorT connector. */
    template<typename PortType>
    class IPortOutputT : virtual public IPortT<PortType> {
    public:
	virtual ~IPortOutputT() {}

	typedef std::shared_ptr<const PortType> pointer;

	/// Subclass implements to potentially provide new data.
	virtual bool extract(pointer& in) = 0;
    };

}

#endif

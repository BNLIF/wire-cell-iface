#ifndef WIRECELL_IPORT
#define WIRECELL_IPORT

namespace WireCell {

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
    };

    /** A templated mix-in satisfying IPort for `port_type_name`
     */
    template<typename PortType>
    class IPortT : virtual IPort {
    public:
	virtual ~IPortT() {}

	typedef PortType port_type;
	typedef std::shared_ptr<const PortType> port_pointer;

	virtual std::string port_type_name() const {
	    return typeid(port_type).name();
	}
    };
}

#endif

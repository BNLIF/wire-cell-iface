#ifndef WIRECELL_IPROCESSOR
#define WIRECELL_IPROCESSOR

#include "WireCellUtil/Interface.h"

#include <boost/any.hpp>

namespace WireCell {


    /** A processor is a synchronous unit of computation.
     *
     * All methods are optional.
     */
    class IProcessor : virtual public Interface {
    public:
	virtual ~IProcessor() {}

	/// Get notification before data flow begins.
	virtual void initialize() = 0;

	/// Get notification after all data flow is over.
	virtual void finalize() = 0;

	/// Implement to receive input data on given port.  Return
	/// false if unable to accept (default).  If data.empty() then
	/// an end-of-input (EOI) on that port has been reached.
	/// Reacting to EOI is implementation-dependent.
	virtual bool input(const boost::any& data, int port=0) = 0;

	/// Produce output data from given port.  Return false if
	/// unable to produce.
	virtual bool output(boost::any& data, int port=0) = 0;

	/// Get notification that the global data stream is no longer
	/// valid.  Unconditionally flush all internal buffers.
	virtual void reset() = 0;

    };


};

#endif

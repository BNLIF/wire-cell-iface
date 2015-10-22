#ifndef WIRECELL_IRECEIVING
#define WIRECELL_IRECEIVING

#include "WireCellUtil/IComponent.h"
#include <string>

namespace WireCell {

    /** A DFP base for any node that accepts input of a certain type.
     */
    template<typename DataType>
    class IReceiving
    {
    public:
	virtual ~IReceiving() {}

	typedef DataType input_type;
	typedef std::shared_ptr< const input_type > input_pointer;

	/// Accept a data object for input.  Return false if unable to
	/// accept.
	virtual bool insert(const input_pointer& in) = 0;
    };

}

#endif

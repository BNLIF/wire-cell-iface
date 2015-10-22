#ifndef WIRECELL_ISENDING
#define WIRECELL_ISENDING

#include "WireCellUtil/IComponent.h"
#include <string>

namespace WireCell {

    /** A DFP base for any node that provides output of a certain type.
     */
    template<typename DataType>
    class ISending
    {
    public:
	virtual ~ISending() {}

	typedef DataType output_type;
	typedef std::shared_ptr< const output_type > output_pointer;

	/// Extract one output data object.  Return true if "out" was
	/// set successfully.
	virtual bool extract(output_pointer& out) = 0;
	
    };

}

#endif

#ifndef WIRECELL_ISENDING
#define WIRECELL_ISENDING

#include <memory>

namespace WireCell {

    /** A DFP base for any node that provides output of a certain type.
     */
    template<typename OutputType>
    class ISending {
    public:
	virtual ~ISending() {}

	// Extract one output data object.  Return true if "out" was
	// set successfully.
	virtual bool extract(std::shared_ptr<const OutputType>& out) = 0;
	
    };

}

#endif

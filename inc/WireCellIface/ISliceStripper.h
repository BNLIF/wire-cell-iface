#ifndef WIRECELL_ISLICESTRIPPER
#define WIRECELL_ISLICESTRIPPER

#include "WireCellIface/ISlice.h"
#include "WireCellIface/IStripSet.h"
#include "WireCellIface/IFunctionNode.h"

namespace WireCell {

    /** A slice stripper produces a set of strips from a slice.

        Note, in the case of detectors with wrapped wires, an
        implementation MAY (or may not) produce strips that span the
        wrapping.

     */
    class ISliceStripper : public IFunctionNode<ISlice, IStripSet> {
    public:
	typedef std::shared_ptr<ISliceStripper> pointer;

	virtual ~ISliceStripper() ;

	virtual std::string signature() {
	   return typeid(ISliceStripper).name();
	}

	// supply:
	// virtual bool operator()(const input_pointer& in, output_pointer& out);
    };
}

#endif

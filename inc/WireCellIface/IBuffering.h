#ifndef WIRECELL_IBUFFERING
#define WIRECELL_IBUFFERING

namespace WireCell {

    /** A DFP base for any node wishing to maintain internal buffers.  
     */
    class IBuffering {
    public:
	virtual ~IBuffering() {}

	// Unconditionally purge all internal buffers.
	virtual void reset() = 0;

	// Flush and process any remaining input buffers and prepare
	// results for immediate output.
	virtual void flush() = 0;
	
    };

}

#endif

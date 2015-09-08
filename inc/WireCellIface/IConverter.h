#ifndef WIRECELL_ICONVERTER
#define WIRECELL_ICONVERTER

namespace WireCell {

    /** A converter allows for input data of one type to be inserted
     * and output data of another type to be extracted.  
     *
     * The caller may call `insert()` to add input data and
     * `extract()` to produce output data.
     *
     * A converter may maintain internal buffering and there are
     * methods exposed to allow this buffering to react to outside
     * commands. 
     *
     * The input stream may be terminated when an End Of Stream (EOS)
     * condition is reached.  A caller of the converter should call
     * `flush()` to indicate EOS and in response the converter should
     * flush any inserted input objects to be ready for extraction as
     * output and arrange a EOS marker object to trail them.  The EOS
     * marker object is as returned by the `eos()` method.
     *
     * If the caller wishes to abandon the current stream it may call
     * `reset()`.  The converter must then unconditionally reset its
     * internal state to prior to when data was first inserted.
     *
     * After EOS or reset, a new data stream may be initiated.
     *
     */
    template<typename InputType, typename OutputType>
    class IConverter {
    public:

	typedef InputType input_type;
	typedef OutputType output_type;

	virtual ~IConverter() {}

	// Unconditionally purge all internal buffers.
	virtual void reset() = 0;

	// Flush any remaining input buffers so they are ready for
	// output.
	virtual void flush() = 0;

	// Accept an data object for input.  Return false if unable to
	// accept.
	virtual bool insert(const input_type& in) = 0;

	// Extract one output data object.  Return true if "out" was
	// set successfully.
	virtual bool extract(output_type& out) = 0;

	// Return an instance of a data object which compares to an
	// end of stream marker.  Implement this if the default
	// output_type instance does not make a suitable EOS marker.
	virtual const output_type& eos() {
	    static output_type empty;
	    return empty;
	}

    };

}

#endif

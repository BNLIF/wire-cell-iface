#ifndef WIRECELL_ICONVERTER
#define WIRECELL_ICONVERTER

namespace WireCell {
    template<typename InputType, typename OutputType>
    class IConverter {
    public:

	typedef InputType input_type;
	typedef OutputType output_type;

	virtual ~IConverter() {}

	virtual void reset() = 0;
	virtual void flush() = 0;
	virtual bool insert(const input_type& in) = 0;
	virtual bool extract(output_type& out) = 0;

    };

}

#endif

#ifndef WIRECELL_IPROCESSOR
#define WIRECELL_IPROCESSOR

#include "WireCellUtil/Interface.h"

namespace WireCell {

    /** A processor is a unit of computation.
     *
     * Instead of a concrete instance inheriting directly from
     * IProcessor, it is recommended to define an intermediate
     * IComponent which aggregates IProcessor and one or more ISink
     * and ISource types.
     */
    class IProcessor : virtual public Interface {
    public:
	virtual ~IProcessor() {}

	/** Perform one unit of processing.
	 *
	 * A true return value is interpreted to mean the internal
	 * state of the object is such that further processing is
	 * possible.
	 */
	virtual bool process() = 0;
    };

    
    /** A sink accepts a unit of data of a particular type. 
     *
     * See also WireCell::IProcessor and IWireCell::ISource.
     */
    template<typename Type>
    class ISink : virtual public Interface {
    public:
	virtual ~ISink() {}

	/// Accept an object of Type, return true if successful.
	// fixme: change to exceptions?
	virtual bool sink(const Type& obj) = 0;
    };


    /** A source produces a unit of data of a particular type. 
     *
     * See also WireCell::IProcessor and IWireCell::ISink.
     */
    template<typename Type>
    class ISource : virtual public Interface {
    public:
	virtual ~ISource() {}

	/// Set <ret>, return true if successful.
	// fixme: change to exceptions?
	virtual bool source(Type& ret) = 0;
    };

};

#endif

#ifndef WIRECELL_ICONVERTER
#define WIRECELL_ICONVERTER

#include "WireCellIface/IPort.h"
#include "WireCellIface/INode.h"

namespace WireCell {

    /** A converter is a simple function-like processor which takes
     * one type of input stream, converting it to one type of output
     * stream.
     */
    template<typename InputType, typename OutputType>
    class IConverterNode : public INode, public IReceiving<InputType> , public ISending<OutputType>
    {
    public:

	virtual port_vector input_ports() const {
	    return port_vector{IReceiving<InputType>::port()};
	}
	virtual port_vector output_ports() const {
	    return port_vector{ISending<OutputType>::port()};
	}

	virtual ~IConverterNode() {}
    };

    template<typename OutputType>
    class ISendingNode : public INode, public ISending<OutputType>
    {
    public:

	virtual port_vector output_ports() const {
	    return port_vector{ISending<OutputType>::port()};
	}

	virtual ~ISendingNode() {}
    };

    template<typename InputType>
    class IReceivingNode : public INode, public IReceiving<InputType>
    {
    public:

	virtual port_vector input_ports() const {
	    return port_vector{IReceiving<InputType>::port()};
	}

	virtual ~IReceivingNode() {}
    };
}

#endif


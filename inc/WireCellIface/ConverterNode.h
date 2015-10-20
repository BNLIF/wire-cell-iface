#ifndef WIRECELL_CONVERTERNODE
#define WIRECELL_CONVERTERNODE

#include "WireCellIface/INode.h"
#include "WireCellIface/SendingPort.h"
#include "WireCellIface/ReceivingPort.h"

namespace WireCell {

    /** Adapter from a IConverter to an INode. */
    template<typename InputType, typename OutputType>
    class ConverterNode : public INode {
    public:
	typedef typename IConverter<InputType,OutputType>::pointer converter_pointer;

	ConverterNode(converter_pointer cvtr) {
	    m_inputs.push_back(make_shared<SendingPort<InputType>(cvtr));
	    m_outputs.push_back(make_shared<ReceivingPort<OutputType>(cvtr));
	}
	virtual ~ConverterNode() {}

    private:
	IPort::port_vector m_inputs, m_outputs;
    };

}

#endif

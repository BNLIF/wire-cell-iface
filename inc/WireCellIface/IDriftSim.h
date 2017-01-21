#ifndef WIRECELLIFACE_IDRIFTSIM_H
#define WIRECELLIFACE_IDRIFTSIM_H

#include "WireCellIface/IQueuedoutNode.h"
#include "WireCellIface/IDepo.h"
#include "WireCellIface/IFrame.h"

namespace WireCell {

    class IDriftSim : public IQueuedoutNode<IDepo, IFrame>
    {
    public:
	virtual ~IDrifter() {}

	virtual std::string signature() {
	   return typeid(IDrifter).name();
	}
    };
    
}


#endif /* IDRIFTSIM_H */

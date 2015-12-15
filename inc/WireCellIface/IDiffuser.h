#ifndef WIRECELL_IDIFFUSER
#define WIRECELL_IDIFFUSER

#include "WireCellIface/IQueuedoutNode.h"

#include "WireCellIface/IDepo.h"
#include "WireCellIface/IDiffusion.h"


namespace WireCell {

    /** Interface for a diffuser.  This buffer node takes one
     * deposition and returns one diffusion.
     */
    class IDiffuser : public IQueuedoutNode<IDepo, IDiffusion>
    {
    public:
	virtual ~IDiffuser() {};


	virtual std::string signature() {
	    return typeid(IDiffuser).name();
	}


    };



};

#endif

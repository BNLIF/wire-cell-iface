#ifndef WIRECELL_IDIFFUSER
#define WIRECELL_IDIFFUSER

#include "WireCellIface/IBufferNode.h"

#include "WireCellIface/IDepo.h"
#include "WireCellIface/IDiffusion.h"


namespace WireCell {

    /** Interface for a diffuser.  This buffer node takes one
     * deposition and returns one diffusion.
     */
    class IDiffuser : public IBufferNode<IDepo, IDiffusion>
    {
    public:
	virtual ~IDiffuser() {};
    };


};

#endif

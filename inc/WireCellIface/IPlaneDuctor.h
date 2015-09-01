#ifndef WIRECELL_IPLANEDUCTOR
#define WIRECELL_IPLANEDUCTOR

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IProcessor.h"
#include "WireCellIface/IDepo.h"
#include "WireCellIface/IPlaneSlice.h"

namespace WireCell {

    /**
     * The PlaneDuctor ("ductor" = either an inductor or a conductor)
     * produces digitized charge signals on its plane of wires from
     * depositions that have been drifted to the plane.  It handles
     * the buffering required for diffusion to be applied, as well as
     * actually applying it.  There is one PlaneDuctor per plane.  See
     * also WireCell::Digitizer.
    */
    class IPlaneDuctor : public IComponent<IPlaneDuctor>
		       , public IProcessor
		       , public ISink<IDepo::pointer>
		       , public ISource<IPlaneSlice::pointer>
    {
    public:
	virtual ~IPlaneDuctor() {};
    };

}

#endif

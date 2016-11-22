#ifndef WIRECELL_IPLANEDUCTOR
#define WIRECELL_IPLANEDUCTOR

#include "WireCellIface/IQueuedoutNode.h"
#include "WireCellIface/IDiffusion.h"
#include "WireCellIface/IPlaneSlice.h"

namespace WireCell {

    /**
     * The PlaneDuctor ("ductor" = either an inductor or a conductor)
     * produces charge signals on its plane of wires from
     * diffusions (diffuse depositions) that have already been drifted
     * to the vicinity of the plane.  There is one PlaneDuctor per
     * plane.  See also WireCell::IDigitizer.
    */
    class IPlaneDuctor : public IQueuedoutNode<IDiffusion, IPlaneSlice>
    {
    public:

	virtual ~IPlaneDuctor() {};

	virtual std::string signature() {
	   return typeid(IPlaneDuctor).name();
	}

    };

}

#endif

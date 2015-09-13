#ifndef WIRECELL_IPLANEDUCTOR
#define WIRECELL_IPLANEDUCTOR

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IConverter.h"
#include "WireCellIface/IDiffusion.h"
#include "WireCellIface/IPlaneSlice.h"

namespace WireCell {

    /**
     * The PlaneDuctor ("ductor" = either an inductor or a conductor)
     * produces digitized charge signals on its plane of wires from
     * diffusions (diffuse depositions) that have already been drifted
     * to the vicinity of the plane.  There is one PlaneDuctor per
     * plane.  See also WireCell::Digitizer.
    */
    class IPlaneDuctor : public IComponent<IPlaneDuctor>
		       , public IConverter<IDiffusion::pointer, IPlaneSlice::pointer>
    {
    public:
	virtual ~IPlaneDuctor() {};
    };

}

#endif

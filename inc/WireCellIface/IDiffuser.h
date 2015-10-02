#ifndef WIRECELL_IDIFFUSER
#define WIRECELL_IDIFFUSER

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IConverter.h"

#include "WireCellIface/IDepo.h"
#include "WireCellIface/IDiffusion.h"


namespace WireCell {

    class IDiffuser
	: public IComponent<IDiffuser>
	, public IConverter<IDepo, IDiffusion>
    {
    public:
	virtual ~IDiffuser() {};
    };


};

#endif

#ifndef WIRECELLIFACE_ICONFIGURABLE
#define WIRECELLIFACE_ICONFIGURABLE

#include "WireCellUtil/Configuration.h"
#include "WireCellUtil/Interface.h"

namespace WireCell {

    /** Interface by which a class may be configured.
     *
     * Configuration is via a Boost property tree.
     */
    class IConfigurable : virtual public Interface {
    public:
	virtual ~IConfigurable();

	/// Accept a configuration.
	virtual void configure(const WireCell::Configuration& config) = 0;
	
	/// Override to return a hard-coded default configuration.
	virtual WireCell::Configuration default_configuration() const {
	    return WireCell::Configuration();
	}

    };

}


#endif

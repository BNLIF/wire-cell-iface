#ifndef WIRECELLIFACE_ICONFIGURABLE
#define WIRECELLIFACE_ICONFIGURABLE

#include <boost/property_tree/ptree.hpp>

namespace WireCell {

    namespace Property = boost::property_tree;
    

    /** Interface by which a class may be configured.
     *
     * Configuration is via a Boost property tree.
     */
    class IConfigurable {
    public:
	virtual ~IConfigurable();

	/// Accept a property tree.
	virtual void configure(const Property& properties) = 0;
	
	/// Override to return a hard-coded default property tree.
	virtual Property default_properties() const {
	    return Property();
	}

    };

}


#endif

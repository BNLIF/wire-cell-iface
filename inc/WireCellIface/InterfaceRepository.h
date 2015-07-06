#ifndef WIRECELLIFACE_INTERFACEREPOSITORY
#define WIRECELLIFACE_INTERFACEREPOSITORY

#include <map>

namespace WireCell {

    class InterfaceRepository {
	static InterfaceRepository* me;
	InterfaceRepository();	// see repo()

	typdef std::pair<const char*,const char*> InterInst;
	std::map<InterInst, Interface*> ifaces;

    public:
	~InterfaceRepository();
	
	/// Get the InterfaceRepository
	InterfaceRepository& repo();

	/// Register an interface instance.
	void register(const char* interface_name, const char* instance_name,
		      Interface* instance);


	/// Return a matching interface or NULL.
	Interface* get(const char* interface_name, const char* instance_name=0);

    };

}

#endif

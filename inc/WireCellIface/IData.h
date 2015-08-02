#ifndef WIRECELL_IDATA
#define WIRECELL_IDATA

namespace WireCell {
    template<class Type>
    class IData {
    public:
	typedef std::shared_ptr<const Type> const_ptr;
    };
}


#endif

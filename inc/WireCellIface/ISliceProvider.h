#ifndef WIRECELLIFACE_ISLICEPROVIDER
#define WIRECELLIFACE_ISLICEPROVIDER

#include "WireCellUtil/RandomIter.h"
#include "WireCellIface/ISlice.h"

namespace WireCell {

    /** Interface to a provider of WireCell::ISlice objects.
     */
    class ISliceProvider {
    public:
	virtual ~ISliceProvider();

	typedef RandomIter<ISliceProvider, ISlice> iterator;
	typedef RandomIter<const ISliceProvider, const ISlice> const_iterator;

	/// Return iterator pointing to first ISlice this provider has
	iterator begin();
	const_iterator begin() const;
	
	/// Return Iterator to one past the last ISlice this provider has
	iterator end();
	const_iterator end() const;

	/// Return the total number of slices or -1 if unlimited.
	virtual int size() const = 0;

	/// Return a reference to the numbered slice (counting from 0)
	virtual ISlice& at(int number) = 0;
	virtual const ISlice& at(int number) const;
	
    };

};

#endif

#ifndef WIRECELLIFACE_IFRAMEPROVIDER
#define WIRECELLIFACE_IFRAMEPROVIDER

#include "WireCellUtil/RandomIter.h"
#include "WireCellIface/IFrame.h"
#include "WireCellUtil/Interface.h"

namespace WireCell {

    /** Interface to a provider of WireCell::IFrame objects.
     *
     */
     
    class IFrameProvider : virtual public Interface{
    public:
	virtual ~IFrameProvider();

	typedef RandomIter<IFrameProvider, IFrame> iterator;
	typedef RandomIter<const IFrameProvider, const IFrame> const_iterator;

	/// Return iterator pointing to first IFrame this provider has
	iterator begin();
	const_iterator begin() const;

	/// Return Iterator to one past the last IFrame this provider has
	iterator end();
	const_iterator end() const;

	/// Return the total number of frames or -1 if unlimited.
	virtual int size() const = 0;

	/// Return a reference to the numbered frame (counting from 0)
	virtual IFrame& at(int number) = 0;
	virtual const IFrame& at(int number) const;
	
    };

    WIRECELL_DEFINE_INTERFACE(IFrameProvider);
}

#endif

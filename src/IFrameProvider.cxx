#include "WireCellIface/IFrameProvider.h"

using namespace WireCell;
IFrameProvider::~IFrameProvider()
{
}

IFrameProvider::iterator IFrameProvider::begin()
{
    return IFrameProvider::iterator(*this);
}

IFrameProvider::const_iterator IFrameProvider::begin() const
{
    return IFrameProvider::const_iterator(*this);
}

IFrameProvider::iterator IFrameProvider::end()
{
    return IFrameProvider::iterator(true, *this);
}

IFrameProvider::const_iterator IFrameProvider::end() const
{
    return IFrameProvider::const_iterator(true, *this);
}

const IFrame& IFrameProvider::at(int number) const
{
    return const_cast<IFrameProvider*>(this)->at(number);
}

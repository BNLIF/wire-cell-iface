#include "WireCellIface/ISliceProvider.h"

using namespace WireCell;
ISliceProvider::~ISliceProvider()
{
}

ISliceProvider::iterator ISliceProvider::begin()
{
    return ISliceProvider::iterator(*this);
}

ISliceProvider::const_iterator ISliceProvider::begin() const
{
    return ISliceProvider::const_iterator(*this);
}

ISliceProvider::iterator ISliceProvider::end()
{
    return ISliceProvider::iterator(true, *this);
}

ISliceProvider::const_iterator ISliceProvider::end() const
{
    return ISliceProvider::const_iterator(true, *this);
}

const ISlice& ISliceProvider::at(int number) const
{
    return const_cast<ISliceProvider*>(this)->at(number);
}

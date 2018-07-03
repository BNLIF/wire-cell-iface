/**
   Provides geometrical information about one wire plane in terms of
   its wire direction, pitch, bounding box and individual wires from
   which channel information can be derived.
 */

#ifndef WIRECELLIFACES_IWIREPLANE
#define WIRECELLIFACES_IWIREPLANE

#include "WireCellUtil/IComponent.h"

#include "WireCellUtil/Pimpos.h"

#include "WireCellIface/IWire.h"

namespace WireCell {

    class IWirePlane : public IComponent<IWirePlane> {
    public:

        virtual ~IWirePlane() {}

        virtual int ident() const = 0;

        /// Return a Pimpos object for this wire plane
        virtual const Pimpos* pimpos() const = 0;

        /// Return vector of wire objects ordered by increasing Z.
        virtual const IWire::vector& wires() const = 0;

    };
}

#endif


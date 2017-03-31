/**
   Provides information about an "anode plane" which consists of a
   number of parallel wire planes as IWirePlane objects.
  
 */

#ifndef WIRECELLIFACES_IANODEPLANE
#define WIRECELLIFACES_IANODEPLANE

#include "WireCellUtil/IComponent.h"
#include "WireCellIface/IAnodeFace.h"


namespace WireCell {

    class IAnodePlane : public IComponent<IAnodePlane> {
    public:

        virtual ~IAnodePlane() {}

        /// Return the ident number of this plane.
        virtual int ident() const = 0;

        /// Return number of faces (eg, MicroBooNE=1, DUNE=2)
        virtual int nfaces() const = 0;

        /// Return a anode face by its ident number. 
        virtual IAnodeFace::pointer face(int ident) const = 0;


    };
}

#endif


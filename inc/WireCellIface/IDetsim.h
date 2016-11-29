/** An interface for a class that turns depositions into frames.
 *
 */

#ifndef WIRECELL_IDETSIM
#define WIRECELL_IDETSIM

#include "WireCellIface/IQueuedoutNode.h"

#include "WireCellIface/IDepo.h"
#include "WireCellIface/IFrame.h"


namespace WireCell {

    /** 

     */
    class IDetsim : public IQueuedoutNode<IDepo, IFrame> {
    public:
	virtual ~IDetsim() {};


    };


}

#ifndef WIRECELL_SIMPLEFRAME
#define  WIRECELL_SIMPLEFRAME

#include "WireCellIface/IFrame.h"
#include "WireCellUtil/Units.h"
#include <vector>

namespace WireCell {

    /** A simple frame.
     *
     * This is is nothing more than a bag of data.
     */ 
    class SimpleFrame : public IFrame {
    public:

	SimpleFrame(int ident, double time, const ITrace::vector& traces, double tick=0.5*units::microsecond);
	~SimpleFrame();
	virtual int ident() const;
	virtual double time() const;
	virtual double tick() const;
    
	virtual ITrace::shared_vector traces() const;
	virtual ChannelMaskings masks() const;

	// helper methods
	void add_mask(const std::string& label, double value, IFrame::channel_tick_ranges masks);
	

    private:
	int m_ident;
	double m_time, m_tick;
	ITrace::shared_vector m_traces;
	ChannelMaskings m_maskings;
    };

}

#endif

#include "WireCellIface/SimpleFrame.h"

#include <iostream>

using namespace WireCell;
using namespace std;

SimpleFrame::SimpleFrame(int ident, double time, const ITrace::vector& traces, double tick,
			 const Waveform::ChannelMaskMap& cmm)
    : m_ident(ident), m_time(time), m_tick(tick)
    , m_traces(new ITrace::vector(traces.begin(), traces.end()))
    , m_cmm(cmm)
{
//    cerr << "SimpleFrame(" << ident << " , " << time << " , " << traces.size() << ")" << endl;
}
SimpleFrame::~SimpleFrame() {

}
int SimpleFrame::ident() const { return m_ident; }
double SimpleFrame::time() const { return m_time; }
double SimpleFrame::tick() const { return m_tick; }
    
ITrace::shared_vector SimpleFrame::traces() const { return m_traces; }


Waveform::ChannelMaskMap SimpleFrame::masks() const
{
    return m_cmm;
}

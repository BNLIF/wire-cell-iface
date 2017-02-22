#include "WireCellIface/SimpleDepo.h"

using namespace WireCell;

SimpleDepo::SimpleDepo(double t, const WireCell::Point& pos,
		       double charge, IDepo::pointer prior,
                       double extent_long, double extent_tran)
                       
    : m_time(t), m_pos(pos), m_charge(charge), m_prior(prior), m_long(extent_long), m_tran(extent_tran)
{
}

const WireCell::Point& SimpleDepo::pos() const
{
    return m_pos; 
}
double SimpleDepo::time() const 
{ 
    return m_time; 
}
double SimpleDepo::charge() const
{
    return m_charge;
}
WireCell::IDepo::pointer SimpleDepo::prior() const
{
    return m_prior;
}
double SimpleDepo::extent_long() const { return m_long; }
double SimpleDepo::extent_tran() const { return m_tran; }

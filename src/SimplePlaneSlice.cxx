#include "WireCellIface/SimplePlaneSlice.h"

#include <iostream>
using namespace std;
using namespace WireCell;

std::vector<double> SimplePlaneSlice::flatten() const
{
    std::vector<double> ret;
    for (auto indv : m_wcrv) {
	const size_t ind = indv.first;
	const std::vector<double>& vec = indv.second;
	const size_t siz = vec.size();
	if (ret.size() < ind + siz) {
	    ret.resize(ind+siz, 0.0);
	}
	for (size_t i=ind; i < siz; ++i) {
	    ret[ind+i] += vec[i];
	}
    }
    return ret;
}

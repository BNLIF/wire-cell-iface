#ifndef WIRECELL_IRANDOM
#define WIRECELL_IRANDOM

#include "WireCellUtil/IComponent.h"
#include <functional>
#include <complex>

namespace WireCell {

    class IRandom : public IComponent<IRandom> {
    public:
        virtual ~IRandom() {}

        typedef std::function<int()> intfunc_t;
        typedef std::function<double()> realfunc_t;
        typedef std::function<std::complex<double>()> compfunc_t;

        /// Return a function sampling a binomial distribution
        virtual intfunc_t binomial(int max, double prob) = 0;

        /// Return a function sampling a normal distribution.
        virtual realfunc_t normal(double mean, double sigma) = 0;

        /// Return a function sampling a uniform real distribution in
        /// the semi-open [begin,end).
        virtual realfunc_t uniform(double begin, double end) = 0;

        /// Return a function sampling a uniform integer range between
        /// [first,last] inclusive.
        virtual intfunc_t range(int first, int last) = 0;

        /// Return a function sampling a 2D normal distribution.  Real
        /// part is first, imaginary part is second.  Note, the abs()
        /// gives a Rayleigh and the arg() gives a phase.
        virtual compfunc_t binormal(double mean1, double sigma1,
                                    double mean2, double sigma2) = 0;
    };

}

#endif

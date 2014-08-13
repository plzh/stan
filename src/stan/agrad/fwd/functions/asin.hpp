#ifndef STAN__AGRAD__FWD__FUNCTIONS__ASIN_HPP
#define STAN__AGRAD__FWD__FUNCTIONS__ASIN_HPP

#include <stan/agrad/fwd/fvar.hpp>
#include <stan/math/functions/square.hpp>
#include <stan/meta/traits.hpp>
#include <cmath>
#include <complex>

namespace stan {

  namespace agrad {

    template <typename T>
    inline
    fvar<T>
    asin(const fvar<T>& x) {
      using std::asin;
      using std::sqrt;
      using stan::math::square;
      return fvar<T>(asin(x.val_), x.d_ / sqrt(1 - square(x.val_)));
    }
  }
}
#endif

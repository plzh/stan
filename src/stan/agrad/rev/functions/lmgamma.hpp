#ifndef STAN__AGRAD__REV__FUNCTIONS__LMGAMMA_HPP
#define STAN__AGRAD__REV__FUNCTIONS__LMGAMMA_HPP

#include <stan/agrad/rev/internal/dv_vari.hpp>
#include <stan/agrad/rev/var.hpp>
#include <stan/math/constants.hpp>
#include <stan/math/functions/digamma.hpp>
#include <stan/math/functions/lmgamma.hpp>
#include <cmath>
#include <ostream>
#include <valarray>

#include "boost/format/alt_sstream.hpp"
#include "boost/format/alt_sstream_impl.hpp"
#include "boost/format/format_implementation.hpp"
#include "boost/optional/optional.hpp"
#include "stan/agrad/rev/internal/dv_vari.hpp"
#include "stan/agrad/rev/vari.hpp"

namespace stan {
  namespace agrad {

    namespace {
      class lmgamma_dv_vari : public op_dv_vari {
      public:
        lmgamma_dv_vari(int a, vari* bvi) :
          op_dv_vari(stan::math::lmgamma(a, bvi->val_),a,bvi) {
        }
        void chain() {
          double deriv = 0;
          for (int i = 1; i < ad_ + 1; i++)
            deriv += stan::math::digamma(bvi_->val_ + (1.0 - i) / 2.0);
          bvi_->adj_ += adj_ * deriv;
        }
      };
    }

    inline var lmgamma(int a, const stan::agrad::var& b) {
      return var(new lmgamma_dv_vari(a, b.vi_));
    }

  }
}
#endif

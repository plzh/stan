#ifndef STAN__AGRAD__REV__FUNCTIONS__EXP2_HPP
#define STAN__AGRAD__REV__FUNCTIONS__EXP2_HPP

#include <math.h>
#include <stan/agrad/rev/internal/v_vari.hpp>
#include <stan/agrad/rev/var.hpp>
#include <stan/math/constants.hpp>
#include <valarray>

#include "stan/agrad/rev/internal/v_vari.hpp"
#include "stan/agrad/rev/vari.hpp"

namespace stan {
  namespace agrad {

    namespace {
      class exp2_vari : public op_v_vari {
      public:
        exp2_vari(vari* avi) :
          op_v_vari(std::pow(2.0,avi->val_),avi) {
        }
        void chain() {
          avi_->adj_ += adj_ * val_ * stan::math::LOG_2;
        }
      };
    }

    /**
     * Exponentiation base 2 function for variables (C99).
     *
     * For non-variable function, see boost::math::exp2().
     *
     * The derivatie is
     *
     * \f$\frac{d}{dx} 2^x = (\log 2) 2^x\f$.
     * 
     * @param a The variable.
     * @return Two to the power of the specified variable.
     */
    inline var exp2(const stan::agrad::var& a) {
      return var(new exp2_vari(a.vi_));
    }

  }
}
#endif

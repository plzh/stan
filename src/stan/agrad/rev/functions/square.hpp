#ifndef STAN__AGRAD__REV__FUNCTIONS__SQUARE_HPP
#define STAN__AGRAD__REV__FUNCTIONS__SQUARE_HPP

#include <stan/agrad/rev/internal/v_vari.hpp>
#include <stan/agrad/rev/var.hpp>

#include "stan/agrad/rev/internal/v_vari.hpp"
#include "stan/agrad/rev/vari.hpp"

namespace stan {
  namespace agrad {

    namespace {
      class square_vari : public op_v_vari {
      public:
        square_vari(vari* avi) :
          op_v_vari(avi->val_ * avi->val_,avi) {
        }
        void chain() {
          avi_->adj_ += adj_ * 2.0 * avi_->val_;
        }
      };
    }

    /**
     * Return the square of the input variable.
     *
     * <p>Using <code>square(x)</code> is more efficient
     * than using <code>x * x</code>.
     *
     * @param x Variable to square.
     * @return Square of variable.
     */
    inline var square(const var& x) {
      return var(new square_vari(x.vi_));
    }

  }
}
#endif

#ifndef STAN__AGRAD__REV__FUNCTIONS__TGAMMA_HPP
#define STAN__AGRAD__REV__FUNCTIONS__TGAMMA_HPP

#include <boost/math/special_functions/digamma.hpp>
#include <stan/agrad/rev/internal/v_vari.hpp>
#include <stan/agrad/rev/var.hpp>
#include <ostream>

#include "boost/format/alt_sstream.hpp"
#include "boost/format/alt_sstream_impl.hpp"
#include "boost/format/format_implementation.hpp"
#include "boost/math/special_functions/math_fwd.hpp"
#include "boost/optional/optional.hpp"
#include "stan/agrad/rev/internal/v_vari.hpp"
#include "stan/agrad/rev/vari.hpp"

namespace stan {
  namespace agrad {

    namespace {
      class tgamma_vari : public op_v_vari {
      public:
        tgamma_vari(vari* avi) :
          op_v_vari(boost::math::tgamma(avi->val_), avi) {
        }
        void chain() {
          avi_->adj_ += adj_ * val_ * boost::math::digamma(avi_->val_);
        }
      };
    }

    /**
     * Return the Gamma function applied to the specified variable (C99).
     *
     * See boost::math::tgamma() for the double-based version.
     *
     * The derivative with respect to the argument is
     *
     * \f$\frac{d}{dx} \Gamma(x) = \Gamma(x) \Psi^{(0)}(x)\f$
     *
     * where \f$\Psi^{(0)}(x)\f$ is the digamma function.
     *
     * See boost::math::digamma() for the double-based version.
     *
     * @param a Argument to function.
     * @return The Gamma function applied to the specified argument.
     */
    inline var tgamma(const stan::agrad::var& a) {
      return var(new tgamma_vari(a.vi_));
    }

  }
}
#endif

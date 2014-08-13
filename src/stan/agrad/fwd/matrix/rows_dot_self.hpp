#ifndef STAN__AGRAD__REV__MATRIX__ROWS_DOT_SELF_HPP
#define STAN__AGRAD__REV__MATRIX__ROWS_DOT_SELF_HPP

#include <stan/agrad/fwd/fvar.hpp>
#include <stan/agrad/fwd/matrix/dot_self.hpp>
#include <stan/math/matrix/Eigen.hpp>
#include <stan/math/matrix/typedefs.hpp>
#include <vector>

#include "Eigen/src/Core/Matrix.h"
#include "stan/agrad/fwd/matrix/typedefs.hpp"

namespace stan {
  namespace agrad {

template <typename T> struct fvar;

    template<typename T, int R,int C>
    inline Eigen::Matrix<fvar<T>,R,1> 
    rows_dot_self(const Eigen::Matrix<fvar<T>,R,C>& x) {
      Eigen::Matrix<fvar<T>,R,1> ret(x.rows(),1);
      for (size_type i = 0; i < x.rows(); i++) {
        Eigen::Matrix<fvar<T>,1,C> crow = x.row(i);
        ret(i,0) = dot_self(crow);
      }
      return ret;
    }
  }
}
#endif

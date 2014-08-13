#ifndef STAN__MATH__MATRIX__INVERSE_SPD_HPP
#define STAN__MATH__MATRIX__INVERSE_SPD_HPP

#include <stan/math/error_handling/matrix/check_square.hpp>
#include <stan/math/error_handling/matrix/check_symmetric.hpp>
#include <stan/math/matrix/Eigen.hpp>
#include <stdexcept>

#include "Eigen/src/Cholesky/LDLT.h"
#include "Eigen/src/Core/Matrix.h"
#include "Eigen/src/Core/util/Constants.h"

namespace stan {
  namespace math {

    /**
     * Returns the inverse of the specified symmetric, pos/neg-definite matrix.
     * @param m Specified matrix.
     * @return Inverse of the matrix.
     */
    template <typename T>
    inline
    Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
    inverse_spd(const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>& m) {
      stan::math::check_square("inverse_spd(%1%)",m,"m",(double*)0);
      stan::math::check_symmetric("inverse_spd(%1%)",m,"m",(double*)0);
      Eigen::LDLT< Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic> > ldlt(0.5*(m+m.transpose()));
      if (ldlt.info() != Eigen::Success)
        throw std::domain_error("Error in inverse_spd, LDLT factorization failed");
      if (!ldlt.isPositive() || (ldlt.vectorD().array() <= 0).any())
        throw std::domain_error("Error in inverse_spd, matrix not positive definite");
      return ldlt.solve(Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>::Identity(m.rows(),m.cols()));
    }

  }
}
#endif

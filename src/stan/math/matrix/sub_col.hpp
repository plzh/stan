#ifndef STAN__MATH__MATRIX__SUB_COL_HPP
#define STAN__MATH__MATRIX__SUB_COL_HPP

#include <stan/math/error_handling/matrix/check_column_index.hpp>
#include <stan/math/error_handling/matrix/check_row_index.hpp>
#include <stan/math/matrix/Eigen.hpp>
#include <cstddef>

#include "Eigen/src/Core/Matrix.h"
#include "Eigen/src/Core/util/Constants.h"

namespace stan {
  namespace math {

    /**
     * Return a nrows x 1 subcolumn starting at (i-1,j-1).
     *
     * @param m Matrix
     * @param i Starting row + 1
     * @param j Starting column + 1
     * @param nrows Number of rows in block
     **/
    template <typename T>
    inline
    Eigen::Matrix<T,Eigen::Dynamic,1>
    sub_col(const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>& m,
          size_t i, size_t j, size_t nrows) {
      stan::math::check_row_index("sub_col(%1%)",i,m,"i",(double*)0);
      if (nrows > 0)
        stan::math::check_row_index("sub_col(%1%)",i+nrows-1,m,"i+nrows-1",(double*)0);
      stan::math::check_column_index("sub_col(%1%)",j,m,"j",(double*)0);
      return m.block(i - 1,j - 1,nrows,1);
    }
    

  }
}

#endif

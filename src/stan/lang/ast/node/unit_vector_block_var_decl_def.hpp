#ifndef STAN_LANG_AST_NODE_UNIT_VECTOR_BLOCK_VAR_DECL_DEF_HPP
#define STAN_LANG_AST_NODE_UNIT_VECTOR_BLOCK_VAR_DECL_DEF_HPP

#include <stan/lang/ast.hpp>
#include <string>

namespace stan {
  namespace lang {

    unit_vector_block_var_decl::unit_vector_block_var_decl() { }

    unit_vector_block_var_decl::unit_vector_block_var_decl(
                                const std::string& name,
                                const expression& K)
      : var_decl(name, bare_expr_type(vector_type())),
        type_(unit_vector_block_type(K)) { }

    unit_vector_block_var_decl::unit_vector_block_var_decl(
                                const std::string& name,
                                const expression& K,
                                const expression& def)
      : var_decl(name, bare_expr_type(vector_type()), def),
        type_(unit_vector_block_type(K)) { }
  }
}
#endif
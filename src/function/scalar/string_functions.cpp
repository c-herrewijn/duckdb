#include "duckdb/function/scalar/string_functions.hpp"

namespace duckdb {

void BuiltinFunctions::RegisterStringFunctions() {
	Register<LikeFun>();
	Register<LikeEscapeFun>();
}

} // namespace duckdb

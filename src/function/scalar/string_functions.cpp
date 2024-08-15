#include "duckdb/function/scalar/string_functions.hpp"

namespace duckdb {

void BuiltinFunctions::RegisterStringFunctions() {
	Register<LengthFun>();
	Register<LikeFun>();
	Register<LikeEscapeFun>();
	Register<RegexpFun>();
	Register<SubstringFun>();
}

} // namespace duckdb

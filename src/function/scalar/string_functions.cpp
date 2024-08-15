#include "duckdb/function/scalar/string_functions.hpp"

namespace duckdb {

void BuiltinFunctions::RegisterStringFunctions() {
	Register<StripAccentsFun>();
	Register<LengthFun>();
	Register<LikeFun>();
	Register<LikeEscapeFun>();
	Register<RegexpFun>();
	Register<SubstringFun>();
	Register<NFCNormalizeFun>();
}

} // namespace duckdb

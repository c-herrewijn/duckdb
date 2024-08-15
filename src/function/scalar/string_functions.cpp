#include "duckdb/function/scalar/string_functions.hpp"

namespace duckdb {

void BuiltinFunctions::RegisterStringFunctions() {
	Register<StripAccentsFun>();
	Register<ContainsFun>();
	Register<LengthFun>();
	Register<LikeFun>();
	Register<LikeEscapeFun>();
	Register<RegexpFun>();
	Register<SubstringFun>();
	Register<PrefixFun>();
	Register<SuffixFun>();
	Register<NFCNormalizeFun>();
}

} // namespace duckdb

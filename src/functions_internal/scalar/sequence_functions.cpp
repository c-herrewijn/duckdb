#include "duckdb/functions_internal/scalar/sequence_functions.hpp"

namespace duckdb {

void BuiltinFunctions::RegisterSequenceFunctions() {
	Register<NextvalFun>();
	Register<CurrvalFun>();
}

} // namespace duckdb

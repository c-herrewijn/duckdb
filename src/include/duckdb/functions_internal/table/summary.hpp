//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/functions_internal/table/summary.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/functions_internal/table_function.hpp"
#include "duckdb/functions_internal/built_in_functions.hpp"

namespace duckdb {

struct SummaryTableFunction {
	static void RegisterFunction(BuiltinFunctions &set);
};

} // namespace duckdb

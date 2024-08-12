//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/functions_internal/scalar/operators.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/functions_internal/function_set.hpp"
#include "duckdb/functions_internal/scalar_function.hpp"
#include "duckdb/functions_internal/built_in_functions.hpp"

namespace duckdb {

struct AddFun {
	static ScalarFunction GetFunction(const LogicalType &type);
	static ScalarFunction GetFunction(const LogicalType &left_type, const LogicalType &right_type);
	static void RegisterFunction(BuiltinFunctions &set);
};

struct SubtractFun {
	static ScalarFunction GetFunction(const LogicalType &type);
	static ScalarFunction GetFunction(const LogicalType &left_type, const LogicalType &right_type);
	static void RegisterFunction(BuiltinFunctions &set);
};

struct MultiplyFun {
	static void RegisterFunction(BuiltinFunctions &set);
};

struct DivideFun {
	static void RegisterFunction(BuiltinFunctions &set);
};

struct ModFun {
	static void RegisterFunction(BuiltinFunctions &set);
};

} // namespace duckdb

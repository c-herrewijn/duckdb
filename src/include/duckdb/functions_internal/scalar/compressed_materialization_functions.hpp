//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/functions_internal/scalar/compressed_materialization_functions.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/functions_internal/built_in_functions.hpp"
#include "duckdb/functions_internal/function_set.hpp"

namespace duckdb {

struct CompressedMaterializationFunctions {
	//! The types we compress integral types to
	static const vector<LogicalType> IntegralTypes();
	//! The types we compress strings to
	static const vector<LogicalType> StringTypes();

	static unique_ptr<FunctionData> Bind(ClientContext &context, ScalarFunction &bound_function,
	                                     vector<unique_ptr<Expression>> &arguments);
};

//! Needed for (de)serialization without binding
enum class CompressedMaterializationDirection : uint8_t { INVALID = 0, COMPRESS = 1, DECOMPRESS = 2 };

struct CMIntegralCompressFun {
	static ScalarFunction GetFunction(const LogicalType &input_type, const LogicalType &result_type);
	static void RegisterFunction(BuiltinFunctions &set);
};

struct CMIntegralDecompressFun {
	static ScalarFunction GetFunction(const LogicalType &input_type, const LogicalType &result_type);
	static void RegisterFunction(BuiltinFunctions &set);
};

struct CMStringCompressFun {
	static ScalarFunction GetFunction(const LogicalType &result_type);
	static void RegisterFunction(BuiltinFunctions &set);
};

struct CMStringDecompressFun {
	static ScalarFunction GetFunction(const LogicalType &input_type);
	static void RegisterFunction(BuiltinFunctions &set);
};

} // namespace duckdb

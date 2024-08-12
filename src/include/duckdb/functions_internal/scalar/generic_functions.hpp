//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/functions_internal/scalar/generic_functions.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/functions_internal/scalar_function.hpp"
#include "duckdb/functions_internal/function_set.hpp"
#include "duckdb/functions_internal/built_in_functions.hpp"
#include "duckdb/common/serializer/serializer.hpp"
#include "duckdb/common/serializer/deserializer.hpp"

namespace duckdb {
class BoundFunctionExpression;

struct ConstantOrNull {
	static ScalarFunction GetFunction(const LogicalType &return_type);
	static unique_ptr<FunctionData> Bind(Value value);
	static bool IsConstantOrNull(BoundFunctionExpression &expr, const Value &val);
	static void RegisterFunction(BuiltinFunctions &set);
};

struct ExportAggregateFunctionBindData : public FunctionData {
	unique_ptr<BoundAggregateExpression> aggregate;
	explicit ExportAggregateFunctionBindData(unique_ptr<Expression> aggregate_p);
	unique_ptr<FunctionData> Copy() const override;
	bool Equals(const FunctionData &other_p) const override;
};

struct ExportAggregateFunction {
	static unique_ptr<BoundAggregateExpression> Bind(unique_ptr<BoundAggregateExpression> child_aggregate);
	static ScalarFunction GetCombine();
	static ScalarFunction GetFinalize();
	static void RegisterFunction(BuiltinFunctions &set);
};

struct GetVariableFun {
	static void RegisterFunction(BuiltinFunctions &set);
};

} // namespace duckdb

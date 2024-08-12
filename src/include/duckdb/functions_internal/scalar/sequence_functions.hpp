//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/functions_internal/scalar/sequence_functions.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/catalog/catalog_entry/sequence_catalog_entry.hpp"
#include "duckdb/functions_internal/scalar_function.hpp"
#include "duckdb/functions_internal/function_set.hpp"
#include "duckdb/functions_internal/built_in_functions.hpp"

namespace duckdb {

struct NextvalBindData : public FunctionData {
	explicit NextvalBindData(SequenceCatalogEntry &sequence) : sequence(sequence), create_info(sequence.GetInfo()) {
	}

	//! The sequence to use for the nextval computation; only if the sequence is a constant
	SequenceCatalogEntry &sequence;

	//! The CreateInfo for the above sequence, if it exists
	unique_ptr<CreateInfo> create_info;

	unique_ptr<FunctionData> Copy() const override {
		return make_uniq<NextvalBindData>(sequence);
	}

	bool Equals(const FunctionData &other_p) const override {
		auto &other = other_p.Cast<NextvalBindData>();
		return RefersToSameObject(sequence, other.sequence);
	}
};

struct NextvalFun {
	static void RegisterFunction(BuiltinFunctions &set);
};

struct CurrvalFun {
	static void RegisterFunction(BuiltinFunctions &set);
};
} // namespace duckdb

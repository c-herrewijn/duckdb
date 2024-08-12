//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/catalog/catalog_entry/pragma_function_catalog_entry.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/catalog/catalog_entry/function_entry.hpp"
#include "duckdb/functions_internal/pragma_function.hpp"
#include "duckdb/functions_internal/function_set.hpp"

namespace duckdb {

class Catalog;
struct CreatePragmaFunctionInfo;

//! A table function in the catalog
class PragmaFunctionCatalogEntry : public FunctionEntry {
public:
	static constexpr const CatalogType Type = CatalogType::PRAGMA_FUNCTION_ENTRY;
	static constexpr const char *Name = "pragma function";

public:
	PragmaFunctionCatalogEntry(Catalog &catalog, SchemaCatalogEntry &schema, CreatePragmaFunctionInfo &info);

	//! The pragma functions
	PragmaFunctionSet functions;
};
} // namespace duckdb

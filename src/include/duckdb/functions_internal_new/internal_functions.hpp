//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/functions_internal_new/internal_functions.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/common/common.hpp"

namespace duckdb {

class Catalog;
struct CatalogTransaction;

struct CoreFunctions {
	static void RegisterFunctions(Catalog &catalog, CatalogTransaction transaction);
};

} // namespace duckdb

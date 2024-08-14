#pragma once

#include "duckdb/common/typedefs.hpp"

namespace duckdb {

idx_t LowerLength(const char *input_data, idx_t input_length);
void LowerCase(const char *input_data, idx_t input_length, char *result_data);

} // namespace duckdb

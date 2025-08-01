#pragma once

#include "duckdb.h"

//===--------------------------------------------------------------------===//
// Function pointer struct
//===--------------------------------------------------------------------===//
typedef struct {
	// v1.2.0
	duckdb_state (*duckdb_open)(const char *path, duckdb_database *out_database);
	duckdb_state (*duckdb_open_ext)(const char *path, duckdb_database *out_database, duckdb_config config,
	                                char **out_error);
	void (*duckdb_close)(duckdb_database *database);
	duckdb_state (*duckdb_connect)(duckdb_database database, duckdb_connection *out_connection);
	void (*duckdb_interrupt)(duckdb_connection connection);
	duckdb_query_progress_type (*duckdb_query_progress)(duckdb_connection connection);
	void (*duckdb_disconnect)(duckdb_connection *connection);
	const char *(*duckdb_library_version)();
	duckdb_state (*duckdb_create_config)(duckdb_config *out_config);
	size_t (*duckdb_config_count)();
	duckdb_state (*duckdb_get_config_flag)(size_t index, const char **out_name, const char **out_description);
	duckdb_state (*duckdb_set_config)(duckdb_config config, const char *name, const char *option);
	void (*duckdb_destroy_config)(duckdb_config *config);
	duckdb_state (*duckdb_query)(duckdb_connection connection, const char *query, duckdb_result *out_result);
	void (*duckdb_destroy_result)(duckdb_result *result);
	const char *(*duckdb_column_name)(duckdb_result *result, idx_t col);
	duckdb_type (*duckdb_column_type)(duckdb_result *result, idx_t col);
	duckdb_statement_type (*duckdb_result_statement_type)(duckdb_result result);
	duckdb_logical_type (*duckdb_column_logical_type)(duckdb_result *result, idx_t col);
	idx_t (*duckdb_column_count)(duckdb_result *result);
	idx_t (*duckdb_rows_changed)(duckdb_result *result);
	const char *(*duckdb_result_error)(duckdb_result *result);
	duckdb_error_type (*duckdb_result_error_type)(duckdb_result *result);
	duckdb_result_type (*duckdb_result_return_type)(duckdb_result result);
	void *(*duckdb_malloc)(size_t size);
	void (*duckdb_free)(void *ptr);
	idx_t (*duckdb_vector_size)();
	bool (*duckdb_string_is_inlined)(duckdb_string_t string);
	uint32_t (*duckdb_string_t_length)(duckdb_string_t string);
	const char *(*duckdb_string_t_data)(duckdb_string_t *string);
	duckdb_date_struct (*duckdb_from_date)(duckdb_date date);
	duckdb_date (*duckdb_to_date)(duckdb_date_struct date);
	bool (*duckdb_is_finite_date)(duckdb_date date);
	duckdb_time_struct (*duckdb_from_time)(duckdb_time time);
	duckdb_time_tz (*duckdb_create_time_tz)(int64_t micros, int32_t offset);
	duckdb_time_tz_struct (*duckdb_from_time_tz)(duckdb_time_tz micros);
	duckdb_time (*duckdb_to_time)(duckdb_time_struct time);
	duckdb_timestamp_struct (*duckdb_from_timestamp)(duckdb_timestamp ts);
	duckdb_timestamp (*duckdb_to_timestamp)(duckdb_timestamp_struct ts);
	bool (*duckdb_is_finite_timestamp)(duckdb_timestamp ts);
	double (*duckdb_hugeint_to_double)(duckdb_hugeint val);
	duckdb_hugeint (*duckdb_double_to_hugeint)(double val);
	double (*duckdb_uhugeint_to_double)(duckdb_uhugeint val);
	duckdb_uhugeint (*duckdb_double_to_uhugeint)(double val);
	duckdb_decimal (*duckdb_double_to_decimal)(double val, uint8_t width, uint8_t scale);
	double (*duckdb_decimal_to_double)(duckdb_decimal val);
	duckdb_state (*duckdb_prepare)(duckdb_connection connection, const char *query,
	                               duckdb_prepared_statement *out_prepared_statement);
	void (*duckdb_destroy_prepare)(duckdb_prepared_statement *prepared_statement);
	const char *(*duckdb_prepare_error)(duckdb_prepared_statement prepared_statement);
	idx_t (*duckdb_nparams)(duckdb_prepared_statement prepared_statement);
	const char *(*duckdb_parameter_name)(duckdb_prepared_statement prepared_statement, idx_t index);
	duckdb_type (*duckdb_param_type)(duckdb_prepared_statement prepared_statement, idx_t param_idx);
	duckdb_logical_type (*duckdb_param_logical_type)(duckdb_prepared_statement prepared_statement, idx_t param_idx);
	duckdb_state (*duckdb_clear_bindings)(duckdb_prepared_statement prepared_statement);
	duckdb_statement_type (*duckdb_prepared_statement_type)(duckdb_prepared_statement statement);
	duckdb_state (*duckdb_bind_value)(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_value val);
	duckdb_state (*duckdb_bind_parameter_index)(duckdb_prepared_statement prepared_statement, idx_t *param_idx_out,
	                                            const char *name);
	duckdb_state (*duckdb_bind_boolean)(duckdb_prepared_statement prepared_statement, idx_t param_idx, bool val);
	duckdb_state (*duckdb_bind_int8)(duckdb_prepared_statement prepared_statement, idx_t param_idx, int8_t val);
	duckdb_state (*duckdb_bind_int16)(duckdb_prepared_statement prepared_statement, idx_t param_idx, int16_t val);
	duckdb_state (*duckdb_bind_int32)(duckdb_prepared_statement prepared_statement, idx_t param_idx, int32_t val);
	duckdb_state (*duckdb_bind_int64)(duckdb_prepared_statement prepared_statement, idx_t param_idx, int64_t val);
	duckdb_state (*duckdb_bind_hugeint)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                    duckdb_hugeint val);
	duckdb_state (*duckdb_bind_uhugeint)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                     duckdb_uhugeint val);
	duckdb_state (*duckdb_bind_decimal)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                    duckdb_decimal val);
	duckdb_state (*duckdb_bind_uint8)(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint8_t val);
	duckdb_state (*duckdb_bind_uint16)(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint16_t val);
	duckdb_state (*duckdb_bind_uint32)(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint32_t val);
	duckdb_state (*duckdb_bind_uint64)(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint64_t val);
	duckdb_state (*duckdb_bind_float)(duckdb_prepared_statement prepared_statement, idx_t param_idx, float val);
	duckdb_state (*duckdb_bind_double)(duckdb_prepared_statement prepared_statement, idx_t param_idx, double val);
	duckdb_state (*duckdb_bind_date)(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_date val);
	duckdb_state (*duckdb_bind_time)(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_time val);
	duckdb_state (*duckdb_bind_timestamp)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                      duckdb_timestamp val);
	duckdb_state (*duckdb_bind_timestamp_tz)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                         duckdb_timestamp val);
	duckdb_state (*duckdb_bind_interval)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                     duckdb_interval val);
	duckdb_state (*duckdb_bind_varchar)(duckdb_prepared_statement prepared_statement, idx_t param_idx, const char *val);
	duckdb_state (*duckdb_bind_varchar_length)(duckdb_prepared_statement prepared_statement, idx_t param_idx,
	                                           const char *val, idx_t length);
	duckdb_state (*duckdb_bind_blob)(duckdb_prepared_statement prepared_statement, idx_t param_idx, const void *data,
	                                 idx_t length);
	duckdb_state (*duckdb_bind_null)(duckdb_prepared_statement prepared_statement, idx_t param_idx);
	duckdb_state (*duckdb_execute_prepared)(duckdb_prepared_statement prepared_statement, duckdb_result *out_result);
	idx_t (*duckdb_extract_statements)(duckdb_connection connection, const char *query,
	                                   duckdb_extracted_statements *out_extracted_statements);
	duckdb_state (*duckdb_prepare_extracted_statement)(duckdb_connection connection,
	                                                   duckdb_extracted_statements extracted_statements, idx_t index,
	                                                   duckdb_prepared_statement *out_prepared_statement);
	const char *(*duckdb_extract_statements_error)(duckdb_extracted_statements extracted_statements);
	void (*duckdb_destroy_extracted)(duckdb_extracted_statements *extracted_statements);
	duckdb_state (*duckdb_pending_prepared)(duckdb_prepared_statement prepared_statement,
	                                        duckdb_pending_result *out_result);
	void (*duckdb_destroy_pending)(duckdb_pending_result *pending_result);
	const char *(*duckdb_pending_error)(duckdb_pending_result pending_result);
	duckdb_pending_state (*duckdb_pending_execute_task)(duckdb_pending_result pending_result);
	duckdb_pending_state (*duckdb_pending_execute_check_state)(duckdb_pending_result pending_result);
	duckdb_state (*duckdb_execute_pending)(duckdb_pending_result pending_result, duckdb_result *out_result);
	bool (*duckdb_pending_execution_is_finished)(duckdb_pending_state pending_state);
	void (*duckdb_destroy_value)(duckdb_value *value);
	duckdb_value (*duckdb_create_varchar)(const char *text);
	duckdb_value (*duckdb_create_varchar_length)(const char *text, idx_t length);
	duckdb_value (*duckdb_create_bool)(bool input);
	duckdb_value (*duckdb_create_int8)(int8_t input);
	duckdb_value (*duckdb_create_uint8)(uint8_t input);
	duckdb_value (*duckdb_create_int16)(int16_t input);
	duckdb_value (*duckdb_create_uint16)(uint16_t input);
	duckdb_value (*duckdb_create_int32)(int32_t input);
	duckdb_value (*duckdb_create_uint32)(uint32_t input);
	duckdb_value (*duckdb_create_uint64)(uint64_t input);
	duckdb_value (*duckdb_create_int64)(int64_t val);
	duckdb_value (*duckdb_create_hugeint)(duckdb_hugeint input);
	duckdb_value (*duckdb_create_uhugeint)(duckdb_uhugeint input);
	duckdb_value (*duckdb_create_float)(float input);
	duckdb_value (*duckdb_create_double)(double input);
	duckdb_value (*duckdb_create_date)(duckdb_date input);
	duckdb_value (*duckdb_create_time)(duckdb_time input);
	duckdb_value (*duckdb_create_time_tz_value)(duckdb_time_tz value);
	duckdb_value (*duckdb_create_timestamp)(duckdb_timestamp input);
	duckdb_value (*duckdb_create_interval)(duckdb_interval input);
	duckdb_value (*duckdb_create_blob)(const uint8_t *data, idx_t length);
	duckdb_value (*duckdb_create_varint)(duckdb_varint input);
	duckdb_value (*duckdb_create_decimal)(duckdb_decimal input);
	duckdb_value (*duckdb_create_bit)(duckdb_bit input);
	duckdb_value (*duckdb_create_uuid)(duckdb_uhugeint input);
	bool (*duckdb_get_bool)(duckdb_value val);
	int8_t (*duckdb_get_int8)(duckdb_value val);
	uint8_t (*duckdb_get_uint8)(duckdb_value val);
	int16_t (*duckdb_get_int16)(duckdb_value val);
	uint16_t (*duckdb_get_uint16)(duckdb_value val);
	int32_t (*duckdb_get_int32)(duckdb_value val);
	uint32_t (*duckdb_get_uint32)(duckdb_value val);
	int64_t (*duckdb_get_int64)(duckdb_value val);
	uint64_t (*duckdb_get_uint64)(duckdb_value val);
	duckdb_hugeint (*duckdb_get_hugeint)(duckdb_value val);
	duckdb_uhugeint (*duckdb_get_uhugeint)(duckdb_value val);
	float (*duckdb_get_float)(duckdb_value val);
	double (*duckdb_get_double)(duckdb_value val);
	duckdb_date (*duckdb_get_date)(duckdb_value val);
	duckdb_time (*duckdb_get_time)(duckdb_value val);
	duckdb_time_tz (*duckdb_get_time_tz)(duckdb_value val);
	duckdb_timestamp (*duckdb_get_timestamp)(duckdb_value val);
	duckdb_interval (*duckdb_get_interval)(duckdb_value val);
	duckdb_logical_type (*duckdb_get_value_type)(duckdb_value val);
	duckdb_blob (*duckdb_get_blob)(duckdb_value val);
	duckdb_varint (*duckdb_get_varint)(duckdb_value val);
	duckdb_decimal (*duckdb_get_decimal)(duckdb_value val);
	duckdb_bit (*duckdb_get_bit)(duckdb_value val);
	duckdb_uhugeint (*duckdb_get_uuid)(duckdb_value val);
	char *(*duckdb_get_varchar)(duckdb_value value);
	duckdb_value (*duckdb_create_struct_value)(duckdb_logical_type type, duckdb_value *values);
	duckdb_value (*duckdb_create_list_value)(duckdb_logical_type type, duckdb_value *values, idx_t value_count);
	duckdb_value (*duckdb_create_array_value)(duckdb_logical_type type, duckdb_value *values, idx_t value_count);
	idx_t (*duckdb_get_map_size)(duckdb_value value);
	duckdb_value (*duckdb_get_map_key)(duckdb_value value, idx_t index);
	duckdb_value (*duckdb_get_map_value)(duckdb_value value, idx_t index);
	bool (*duckdb_is_null_value)(duckdb_value value);
	duckdb_value (*duckdb_create_null_value)();
	idx_t (*duckdb_get_list_size)(duckdb_value value);
	duckdb_value (*duckdb_get_list_child)(duckdb_value value, idx_t index);
	duckdb_value (*duckdb_create_enum_value)(duckdb_logical_type type, uint64_t value);
	uint64_t (*duckdb_get_enum_value)(duckdb_value value);
	duckdb_value (*duckdb_get_struct_child)(duckdb_value value, idx_t index);
	duckdb_logical_type (*duckdb_create_logical_type)(duckdb_type type);
	char *(*duckdb_logical_type_get_alias)(duckdb_logical_type type);
	void (*duckdb_logical_type_set_alias)(duckdb_logical_type type, const char *alias);
	duckdb_logical_type (*duckdb_create_list_type)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_create_array_type)(duckdb_logical_type type, idx_t array_size);
	duckdb_logical_type (*duckdb_create_map_type)(duckdb_logical_type key_type, duckdb_logical_type value_type);
	duckdb_logical_type (*duckdb_create_union_type)(duckdb_logical_type *member_types, const char **member_names,
	                                                idx_t member_count);
	duckdb_logical_type (*duckdb_create_struct_type)(duckdb_logical_type *member_types, const char **member_names,
	                                                 idx_t member_count);
	duckdb_logical_type (*duckdb_create_enum_type)(const char **member_names, idx_t member_count);
	duckdb_logical_type (*duckdb_create_decimal_type)(uint8_t width, uint8_t scale);
	duckdb_type (*duckdb_get_type_id)(duckdb_logical_type type);
	uint8_t (*duckdb_decimal_width)(duckdb_logical_type type);
	uint8_t (*duckdb_decimal_scale)(duckdb_logical_type type);
	duckdb_type (*duckdb_decimal_internal_type)(duckdb_logical_type type);
	duckdb_type (*duckdb_enum_internal_type)(duckdb_logical_type type);
	uint32_t (*duckdb_enum_dictionary_size)(duckdb_logical_type type);
	char *(*duckdb_enum_dictionary_value)(duckdb_logical_type type, idx_t index);
	duckdb_logical_type (*duckdb_list_type_child_type)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_array_type_child_type)(duckdb_logical_type type);
	idx_t (*duckdb_array_type_array_size)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_map_type_key_type)(duckdb_logical_type type);
	duckdb_logical_type (*duckdb_map_type_value_type)(duckdb_logical_type type);
	idx_t (*duckdb_struct_type_child_count)(duckdb_logical_type type);
	char *(*duckdb_struct_type_child_name)(duckdb_logical_type type, idx_t index);
	duckdb_logical_type (*duckdb_struct_type_child_type)(duckdb_logical_type type, idx_t index);
	idx_t (*duckdb_union_type_member_count)(duckdb_logical_type type);
	char *(*duckdb_union_type_member_name)(duckdb_logical_type type, idx_t index);
	duckdb_logical_type (*duckdb_union_type_member_type)(duckdb_logical_type type, idx_t index);
	void (*duckdb_destroy_logical_type)(duckdb_logical_type *type);
	duckdb_state (*duckdb_register_logical_type)(duckdb_connection con, duckdb_logical_type type,
	                                             duckdb_create_type_info info);
	duckdb_data_chunk (*duckdb_create_data_chunk)(duckdb_logical_type *types, idx_t column_count);
	void (*duckdb_destroy_data_chunk)(duckdb_data_chunk *chunk);
	void (*duckdb_data_chunk_reset)(duckdb_data_chunk chunk);
	idx_t (*duckdb_data_chunk_get_column_count)(duckdb_data_chunk chunk);
	duckdb_vector (*duckdb_data_chunk_get_vector)(duckdb_data_chunk chunk, idx_t col_idx);
	idx_t (*duckdb_data_chunk_get_size)(duckdb_data_chunk chunk);
	void (*duckdb_data_chunk_set_size)(duckdb_data_chunk chunk, idx_t size);
	duckdb_logical_type (*duckdb_vector_get_column_type)(duckdb_vector vector);
	void *(*duckdb_vector_get_data)(duckdb_vector vector);
	uint64_t *(*duckdb_vector_get_validity)(duckdb_vector vector);
	void (*duckdb_vector_ensure_validity_writable)(duckdb_vector vector);
	void (*duckdb_vector_assign_string_element)(duckdb_vector vector, idx_t index, const char *str);
	void (*duckdb_vector_assign_string_element_len)(duckdb_vector vector, idx_t index, const char *str, idx_t str_len);
	duckdb_vector (*duckdb_list_vector_get_child)(duckdb_vector vector);
	idx_t (*duckdb_list_vector_get_size)(duckdb_vector vector);
	duckdb_state (*duckdb_list_vector_set_size)(duckdb_vector vector, idx_t size);
	duckdb_state (*duckdb_list_vector_reserve)(duckdb_vector vector, idx_t required_capacity);
	duckdb_vector (*duckdb_struct_vector_get_child)(duckdb_vector vector, idx_t index);
	duckdb_vector (*duckdb_array_vector_get_child)(duckdb_vector vector);
	bool (*duckdb_validity_row_is_valid)(uint64_t *validity, idx_t row);
	void (*duckdb_validity_set_row_validity)(uint64_t *validity, idx_t row, bool valid);
	void (*duckdb_validity_set_row_invalid)(uint64_t *validity, idx_t row);
	void (*duckdb_validity_set_row_valid)(uint64_t *validity, idx_t row);
	duckdb_scalar_function (*duckdb_create_scalar_function)();
	void (*duckdb_destroy_scalar_function)(duckdb_scalar_function *scalar_function);
	void (*duckdb_scalar_function_set_name)(duckdb_scalar_function scalar_function, const char *name);
	void (*duckdb_scalar_function_set_varargs)(duckdb_scalar_function scalar_function, duckdb_logical_type type);
	void (*duckdb_scalar_function_set_special_handling)(duckdb_scalar_function scalar_function);
	void (*duckdb_scalar_function_set_volatile)(duckdb_scalar_function scalar_function);
	void (*duckdb_scalar_function_add_parameter)(duckdb_scalar_function scalar_function, duckdb_logical_type type);
	void (*duckdb_scalar_function_set_return_type)(duckdb_scalar_function scalar_function, duckdb_logical_type type);
	void (*duckdb_scalar_function_set_extra_info)(duckdb_scalar_function scalar_function, void *extra_info,
	                                              duckdb_delete_callback_t destroy);
	void (*duckdb_scalar_function_set_function)(duckdb_scalar_function scalar_function,
	                                            duckdb_scalar_function_t function);
	duckdb_state (*duckdb_register_scalar_function)(duckdb_connection con, duckdb_scalar_function scalar_function);
	void *(*duckdb_scalar_function_get_extra_info)(duckdb_function_info info);
	void (*duckdb_scalar_function_set_error)(duckdb_function_info info, const char *error);
	duckdb_scalar_function_set (*duckdb_create_scalar_function_set)(const char *name);
	void (*duckdb_destroy_scalar_function_set)(duckdb_scalar_function_set *scalar_function_set);
	duckdb_state (*duckdb_add_scalar_function_to_set)(duckdb_scalar_function_set set, duckdb_scalar_function function);
	duckdb_state (*duckdb_register_scalar_function_set)(duckdb_connection con, duckdb_scalar_function_set set);
	duckdb_aggregate_function (*duckdb_create_aggregate_function)();
	void (*duckdb_destroy_aggregate_function)(duckdb_aggregate_function *aggregate_function);
	void (*duckdb_aggregate_function_set_name)(duckdb_aggregate_function aggregate_function, const char *name);
	void (*duckdb_aggregate_function_add_parameter)(duckdb_aggregate_function aggregate_function,
	                                                duckdb_logical_type type);
	void (*duckdb_aggregate_function_set_return_type)(duckdb_aggregate_function aggregate_function,
	                                                  duckdb_logical_type type);
	void (*duckdb_aggregate_function_set_functions)(duckdb_aggregate_function aggregate_function,
	                                                duckdb_aggregate_state_size state_size,
	                                                duckdb_aggregate_init_t state_init,
	                                                duckdb_aggregate_update_t update,
	                                                duckdb_aggregate_combine_t combine,
	                                                duckdb_aggregate_finalize_t finalize);
	void (*duckdb_aggregate_function_set_destructor)(duckdb_aggregate_function aggregate_function,
	                                                 duckdb_aggregate_destroy_t destroy);
	duckdb_state (*duckdb_register_aggregate_function)(duckdb_connection con,
	                                                   duckdb_aggregate_function aggregate_function);
	void (*duckdb_aggregate_function_set_special_handling)(duckdb_aggregate_function aggregate_function);
	void (*duckdb_aggregate_function_set_extra_info)(duckdb_aggregate_function aggregate_function, void *extra_info,
	                                                 duckdb_delete_callback_t destroy);
	void *(*duckdb_aggregate_function_get_extra_info)(duckdb_function_info info);
	void (*duckdb_aggregate_function_set_error)(duckdb_function_info info, const char *error);
	duckdb_aggregate_function_set (*duckdb_create_aggregate_function_set)(const char *name);
	void (*duckdb_destroy_aggregate_function_set)(duckdb_aggregate_function_set *aggregate_function_set);
	duckdb_state (*duckdb_add_aggregate_function_to_set)(duckdb_aggregate_function_set set,
	                                                     duckdb_aggregate_function function);
	duckdb_state (*duckdb_register_aggregate_function_set)(duckdb_connection con, duckdb_aggregate_function_set set);
	duckdb_table_function (*duckdb_create_table_function)();
	void (*duckdb_destroy_table_function)(duckdb_table_function *table_function);
	void (*duckdb_table_function_set_name)(duckdb_table_function table_function, const char *name);
	void (*duckdb_table_function_add_parameter)(duckdb_table_function table_function, duckdb_logical_type type);
	void (*duckdb_table_function_add_named_parameter)(duckdb_table_function table_function, const char *name,
	                                                  duckdb_logical_type type);
	void (*duckdb_table_function_set_extra_info)(duckdb_table_function table_function, void *extra_info,
	                                             duckdb_delete_callback_t destroy);
	void (*duckdb_table_function_set_bind)(duckdb_table_function table_function, duckdb_table_function_bind_t bind);
	void (*duckdb_table_function_set_init)(duckdb_table_function table_function, duckdb_table_function_init_t init);
	void (*duckdb_table_function_set_local_init)(duckdb_table_function table_function,
	                                             duckdb_table_function_init_t init);
	void (*duckdb_table_function_set_function)(duckdb_table_function table_function, duckdb_table_function_t function);
	void (*duckdb_table_function_supports_projection_pushdown)(duckdb_table_function table_function, bool pushdown);
	duckdb_state (*duckdb_register_table_function)(duckdb_connection con, duckdb_table_function function);
	void *(*duckdb_bind_get_extra_info)(duckdb_bind_info info);
	void (*duckdb_bind_add_result_column)(duckdb_bind_info info, const char *name, duckdb_logical_type type);
	idx_t (*duckdb_bind_get_parameter_count)(duckdb_bind_info info);
	duckdb_value (*duckdb_bind_get_parameter)(duckdb_bind_info info, idx_t index);
	duckdb_value (*duckdb_bind_get_named_parameter)(duckdb_bind_info info, const char *name);
	void (*duckdb_bind_set_bind_data)(duckdb_bind_info info, void *bind_data, duckdb_delete_callback_t destroy);
	void (*duckdb_bind_set_cardinality)(duckdb_bind_info info, idx_t cardinality, bool is_exact);
	void (*duckdb_bind_set_error)(duckdb_bind_info info, const char *error);
	void *(*duckdb_init_get_extra_info)(duckdb_init_info info);
	void *(*duckdb_init_get_bind_data)(duckdb_init_info info);
	void (*duckdb_init_set_init_data)(duckdb_init_info info, void *init_data, duckdb_delete_callback_t destroy);
	idx_t (*duckdb_init_get_column_count)(duckdb_init_info info);
	idx_t (*duckdb_init_get_column_index)(duckdb_init_info info, idx_t column_index);
	void (*duckdb_init_set_max_threads)(duckdb_init_info info, idx_t max_threads);
	void (*duckdb_init_set_error)(duckdb_init_info info, const char *error);
	void *(*duckdb_function_get_extra_info)(duckdb_function_info info);
	void *(*duckdb_function_get_bind_data)(duckdb_function_info info);
	void *(*duckdb_function_get_init_data)(duckdb_function_info info);
	void *(*duckdb_function_get_local_init_data)(duckdb_function_info info);
	void (*duckdb_function_set_error)(duckdb_function_info info, const char *error);
	void (*duckdb_add_replacement_scan)(duckdb_database db, duckdb_replacement_callback_t replacement, void *extra_data,
	                                    duckdb_delete_callback_t delete_callback);
	void (*duckdb_replacement_scan_set_function_name)(duckdb_replacement_scan_info info, const char *function_name);
	void (*duckdb_replacement_scan_add_parameter)(duckdb_replacement_scan_info info, duckdb_value parameter);
	void (*duckdb_replacement_scan_set_error)(duckdb_replacement_scan_info info, const char *error);
	duckdb_value (*duckdb_profiling_info_get_metrics)(duckdb_profiling_info info);
	idx_t (*duckdb_profiling_info_get_child_count)(duckdb_profiling_info info);
	duckdb_profiling_info (*duckdb_profiling_info_get_child)(duckdb_profiling_info info, idx_t index);
	duckdb_state (*duckdb_appender_create)(duckdb_connection connection, const char *schema, const char *table,
	                                       duckdb_appender *out_appender);
	duckdb_state (*duckdb_appender_create_ext)(duckdb_connection connection, const char *catalog, const char *schema,
	                                           const char *table, duckdb_appender *out_appender);
	idx_t (*duckdb_appender_column_count)(duckdb_appender appender);
	duckdb_logical_type (*duckdb_appender_column_type)(duckdb_appender appender, idx_t col_idx);
	const char *(*duckdb_appender_error)(duckdb_appender appender);
	duckdb_state (*duckdb_appender_flush)(duckdb_appender appender);
	duckdb_state (*duckdb_appender_close)(duckdb_appender appender);
	duckdb_state (*duckdb_appender_destroy)(duckdb_appender *appender);
	duckdb_state (*duckdb_appender_add_column)(duckdb_appender appender, const char *name);
	duckdb_state (*duckdb_appender_clear_columns)(duckdb_appender appender);
	duckdb_state (*duckdb_append_data_chunk)(duckdb_appender appender, duckdb_data_chunk chunk);
	duckdb_state (*duckdb_table_description_create)(duckdb_connection connection, const char *schema, const char *table,
	                                                duckdb_table_description *out);
	duckdb_state (*duckdb_table_description_create_ext)(duckdb_connection connection, const char *catalog,
	                                                    const char *schema, const char *table,
	                                                    duckdb_table_description *out);
	void (*duckdb_table_description_destroy)(duckdb_table_description *table_description);
	const char *(*duckdb_table_description_error)(duckdb_table_description table_description);
	duckdb_state (*duckdb_column_has_default)(duckdb_table_description table_description, idx_t index, bool *out);
	char *(*duckdb_table_description_get_column_name)(duckdb_table_description table_description, idx_t index);
	void (*duckdb_execute_tasks)(duckdb_database database, idx_t max_tasks);
	duckdb_task_state (*duckdb_create_task_state)(duckdb_database database);
	void (*duckdb_execute_tasks_state)(duckdb_task_state state);
	idx_t (*duckdb_execute_n_tasks_state)(duckdb_task_state state, idx_t max_tasks);
	void (*duckdb_finish_execution)(duckdb_task_state state);
	bool (*duckdb_task_state_is_finished)(duckdb_task_state state);
	void (*duckdb_destroy_task_state)(duckdb_task_state state);
	bool (*duckdb_execution_is_finished)(duckdb_connection con);
	duckdb_data_chunk (*duckdb_fetch_chunk)(duckdb_result result);
	duckdb_cast_function (*duckdb_create_cast_function)();
	void (*duckdb_cast_function_set_source_type)(duckdb_cast_function cast_function, duckdb_logical_type source_type);
	void (*duckdb_cast_function_set_target_type)(duckdb_cast_function cast_function, duckdb_logical_type target_type);
	void (*duckdb_cast_function_set_implicit_cast_cost)(duckdb_cast_function cast_function, int64_t cost);
	void (*duckdb_cast_function_set_function)(duckdb_cast_function cast_function, duckdb_cast_function_t function);
	void (*duckdb_cast_function_set_extra_info)(duckdb_cast_function cast_function, void *extra_info,
	                                            duckdb_delete_callback_t destroy);
	void *(*duckdb_cast_function_get_extra_info)(duckdb_function_info info);
	duckdb_cast_mode (*duckdb_cast_function_get_cast_mode)(duckdb_function_info info);
	void (*duckdb_cast_function_set_error)(duckdb_function_info info, const char *error);
	void (*duckdb_cast_function_set_row_error)(duckdb_function_info info, const char *error, idx_t row,
	                                           duckdb_vector output);
	duckdb_state (*duckdb_register_cast_function)(duckdb_connection con, duckdb_cast_function cast_function);
	void (*duckdb_destroy_cast_function)(duckdb_cast_function *cast_function);
	bool (*duckdb_is_finite_timestamp_s)(duckdb_timestamp_s ts);
	bool (*duckdb_is_finite_timestamp_ms)(duckdb_timestamp_ms ts);
	bool (*duckdb_is_finite_timestamp_ns)(duckdb_timestamp_ns ts);
	duckdb_value (*duckdb_create_timestamp_tz)(duckdb_timestamp input);
	duckdb_value (*duckdb_create_timestamp_s)(duckdb_timestamp_s input);
	duckdb_value (*duckdb_create_timestamp_ms)(duckdb_timestamp_ms input);
	duckdb_value (*duckdb_create_timestamp_ns)(duckdb_timestamp_ns input);
	duckdb_timestamp (*duckdb_get_timestamp_tz)(duckdb_value val);
	duckdb_timestamp_s (*duckdb_get_timestamp_s)(duckdb_value val);
	duckdb_timestamp_ms (*duckdb_get_timestamp_ms)(duckdb_value val);
	duckdb_timestamp_ns (*duckdb_get_timestamp_ns)(duckdb_value val);
	duckdb_state (*duckdb_append_value)(duckdb_appender appender, duckdb_value value);
	duckdb_profiling_info (*duckdb_get_profiling_info)(duckdb_connection connection);
	duckdb_value (*duckdb_profiling_info_get_value)(duckdb_profiling_info info, const char *key);
	duckdb_state (*duckdb_appender_begin_row)(duckdb_appender appender);
	duckdb_state (*duckdb_appender_end_row)(duckdb_appender appender);
	duckdb_state (*duckdb_append_default)(duckdb_appender appender);
	duckdb_state (*duckdb_append_bool)(duckdb_appender appender, bool value);
	duckdb_state (*duckdb_append_int8)(duckdb_appender appender, int8_t value);
	duckdb_state (*duckdb_append_int16)(duckdb_appender appender, int16_t value);
	duckdb_state (*duckdb_append_int32)(duckdb_appender appender, int32_t value);
	duckdb_state (*duckdb_append_int64)(duckdb_appender appender, int64_t value);
	duckdb_state (*duckdb_append_hugeint)(duckdb_appender appender, duckdb_hugeint value);
	duckdb_state (*duckdb_append_uint8)(duckdb_appender appender, uint8_t value);
	duckdb_state (*duckdb_append_uint16)(duckdb_appender appender, uint16_t value);
	duckdb_state (*duckdb_append_uint32)(duckdb_appender appender, uint32_t value);
	duckdb_state (*duckdb_append_uint64)(duckdb_appender appender, uint64_t value);
	duckdb_state (*duckdb_append_uhugeint)(duckdb_appender appender, duckdb_uhugeint value);
	duckdb_state (*duckdb_append_float)(duckdb_appender appender, float value);
	duckdb_state (*duckdb_append_double)(duckdb_appender appender, double value);
	duckdb_state (*duckdb_append_date)(duckdb_appender appender, duckdb_date value);
	duckdb_state (*duckdb_append_time)(duckdb_appender appender, duckdb_time value);
	duckdb_state (*duckdb_append_timestamp)(duckdb_appender appender, duckdb_timestamp value);
	duckdb_state (*duckdb_append_interval)(duckdb_appender appender, duckdb_interval value);
	duckdb_state (*duckdb_append_varchar)(duckdb_appender appender, const char *val);
	duckdb_state (*duckdb_append_varchar_length)(duckdb_appender appender, const char *val, idx_t length);
	duckdb_state (*duckdb_append_blob)(duckdb_appender appender, const void *data, idx_t length);
	duckdb_state (*duckdb_append_null)(duckdb_appender appender);
	// These functions have been deprecated and may be removed in future versions of DuckDB

	idx_t (*duckdb_row_count)(duckdb_result *result);
	void *(*duckdb_column_data)(duckdb_result *result, idx_t col);
	bool *(*duckdb_nullmask_data)(duckdb_result *result, idx_t col);
	duckdb_data_chunk (*duckdb_result_get_chunk)(duckdb_result result, idx_t chunk_index);
	bool (*duckdb_result_is_streaming)(duckdb_result result);
	idx_t (*duckdb_result_chunk_count)(duckdb_result result);
	bool (*duckdb_value_boolean)(duckdb_result *result, idx_t col, idx_t row);
	int8_t (*duckdb_value_int8)(duckdb_result *result, idx_t col, idx_t row);
	int16_t (*duckdb_value_int16)(duckdb_result *result, idx_t col, idx_t row);
	int32_t (*duckdb_value_int32)(duckdb_result *result, idx_t col, idx_t row);
	int64_t (*duckdb_value_int64)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_hugeint (*duckdb_value_hugeint)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_uhugeint (*duckdb_value_uhugeint)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_decimal (*duckdb_value_decimal)(duckdb_result *result, idx_t col, idx_t row);
	uint8_t (*duckdb_value_uint8)(duckdb_result *result, idx_t col, idx_t row);
	uint16_t (*duckdb_value_uint16)(duckdb_result *result, idx_t col, idx_t row);
	uint32_t (*duckdb_value_uint32)(duckdb_result *result, idx_t col, idx_t row);
	uint64_t (*duckdb_value_uint64)(duckdb_result *result, idx_t col, idx_t row);
	float (*duckdb_value_float)(duckdb_result *result, idx_t col, idx_t row);
	double (*duckdb_value_double)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_date (*duckdb_value_date)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_time (*duckdb_value_time)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_timestamp (*duckdb_value_timestamp)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_interval (*duckdb_value_interval)(duckdb_result *result, idx_t col, idx_t row);
	char *(*duckdb_value_varchar)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_string (*duckdb_value_string)(duckdb_result *result, idx_t col, idx_t row);
	char *(*duckdb_value_varchar_internal)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_string (*duckdb_value_string_internal)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_blob (*duckdb_value_blob)(duckdb_result *result, idx_t col, idx_t row);
	bool (*duckdb_value_is_null)(duckdb_result *result, idx_t col, idx_t row);
	duckdb_state (*duckdb_execute_prepared_streaming)(duckdb_prepared_statement prepared_statement,
	                                                  duckdb_result *out_result);
	duckdb_state (*duckdb_pending_prepared_streaming)(duckdb_prepared_statement prepared_statement,
	                                                  duckdb_pending_result *out_result);
	duckdb_state (*duckdb_query_arrow)(duckdb_connection connection, const char *query, duckdb_arrow *out_result);
	duckdb_state (*duckdb_query_arrow_schema)(duckdb_arrow result, duckdb_arrow_schema *out_schema);
	duckdb_state (*duckdb_prepared_arrow_schema)(duckdb_prepared_statement prepared, duckdb_arrow_schema *out_schema);
	void (*duckdb_result_arrow_array)(duckdb_result result, duckdb_data_chunk chunk, duckdb_arrow_array *out_array);
	duckdb_state (*duckdb_query_arrow_array)(duckdb_arrow result, duckdb_arrow_array *out_array);
	idx_t (*duckdb_arrow_column_count)(duckdb_arrow result);
	idx_t (*duckdb_arrow_row_count)(duckdb_arrow result);
	idx_t (*duckdb_arrow_rows_changed)(duckdb_arrow result);
	const char *(*duckdb_query_arrow_error)(duckdb_arrow result);
	void (*duckdb_destroy_arrow)(duckdb_arrow *result);
	void (*duckdb_destroy_arrow_stream)(duckdb_arrow_stream *stream_p);
	duckdb_state (*duckdb_execute_prepared_arrow)(duckdb_prepared_statement prepared_statement,
	                                              duckdb_arrow *out_result);
	duckdb_state (*duckdb_arrow_scan)(duckdb_connection connection, const char *table_name, duckdb_arrow_stream arrow);
	duckdb_state (*duckdb_arrow_array_scan)(duckdb_connection connection, const char *table_name,
	                                        duckdb_arrow_schema arrow_schema, duckdb_arrow_array arrow_array,
	                                        duckdb_arrow_stream *out_stream);
	duckdb_data_chunk (*duckdb_stream_fetch_chunk)(duckdb_result result);
	// Exposing the instance cache

	duckdb_instance_cache (*duckdb_create_instance_cache)();
	duckdb_state (*duckdb_get_or_create_from_cache)(duckdb_instance_cache instance_cache, const char *path,
	                                                duckdb_database *out_database, duckdb_config config,
	                                                char **out_error);
	void (*duckdb_destroy_instance_cache)(duckdb_instance_cache *instance_cache);
	// New append functions that are added

	duckdb_state (*duckdb_append_default_to_chunk)(duckdb_appender appender, duckdb_data_chunk chunk, idx_t col,
	                                               idx_t row);
	duckdb_error_data (*duckdb_appender_error_data)(duckdb_appender appender);
	// New arrow interface functions

	duckdb_error_data (*duckdb_to_arrow_schema)(duckdb_arrow_options arrow_options, duckdb_logical_type *types,
	                                            const char **names, idx_t column_count, struct ArrowSchema *out_schema);
	duckdb_error_data (*duckdb_data_chunk_to_arrow)(duckdb_arrow_options arrow_options, duckdb_data_chunk chunk,
	                                                struct ArrowArray *out_arrow_array);
	duckdb_error_data (*duckdb_schema_from_arrow)(duckdb_connection connection, struct ArrowSchema *schema,
	                                              duckdb_arrow_converted_schema *out_types);
	duckdb_error_data (*duckdb_data_chunk_from_arrow)(duckdb_connection connection, struct ArrowArray *arrow_array,
	                                                  duckdb_arrow_converted_schema converted_schema,
	                                                  duckdb_data_chunk *out_chunk);
	void (*duckdb_destroy_arrow_converted_schema)(duckdb_arrow_converted_schema *arrow_converted_schema);
	// New functions for duckdb error data

	duckdb_error_data (*duckdb_create_error_data)(duckdb_error_type type, const char *message);
	void (*duckdb_destroy_error_data)(duckdb_error_data *error_data);
	duckdb_error_type (*duckdb_error_data_error_type)(duckdb_error_data error_data);
	const char *(*duckdb_error_data_message)(duckdb_error_data error_data);
	bool (*duckdb_error_data_has_error)(duckdb_error_data error_data);
	// API to create and manipulate expressions

	void (*duckdb_destroy_expression)(duckdb_expression *expr);
	duckdb_logical_type (*duckdb_expression_return_type)(duckdb_expression expr);
	bool (*duckdb_expression_is_foldable)(duckdb_expression expr);
	duckdb_error_data (*duckdb_expression_fold)(duckdb_client_context context, duckdb_expression expr,
	                                            duckdb_value *out_value);
	// New functions around the client context

	idx_t (*duckdb_client_context_get_connection_id)(duckdb_client_context context);
	void (*duckdb_destroy_client_context)(duckdb_client_context *context);
	void (*duckdb_connection_get_client_context)(duckdb_connection connection, duckdb_client_context *out_context);
	duckdb_value (*duckdb_get_table_names)(duckdb_connection connection, const char *query, bool qualified);
	void (*duckdb_connection_get_arrow_options)(duckdb_connection connection, duckdb_arrow_options *out_arrow_options);
	void (*duckdb_destroy_arrow_options)(duckdb_arrow_options *arrow_options);
	// New query execution functions

	duckdb_arrow_options (*duckdb_result_get_arrow_options)(duckdb_result *result);
	// New functions around scalar function binding

	void (*duckdb_scalar_function_set_bind)(duckdb_scalar_function scalar_function, duckdb_scalar_function_bind_t bind);
	void (*duckdb_scalar_function_bind_set_error)(duckdb_bind_info info, const char *error);
	void (*duckdb_scalar_function_get_client_context)(duckdb_bind_info info, duckdb_client_context *out_context);
	void (*duckdb_scalar_function_set_bind_data)(duckdb_bind_info info, void *bind_data,
	                                             duckdb_delete_callback_t destroy);
	void *(*duckdb_scalar_function_get_bind_data)(duckdb_function_info info);
	void *(*duckdb_scalar_function_bind_get_extra_info)(duckdb_bind_info info);
	idx_t (*duckdb_scalar_function_bind_get_argument_count)(duckdb_bind_info info);
	duckdb_expression (*duckdb_scalar_function_bind_get_argument)(duckdb_bind_info info, idx_t index);
	// New string functions that are added

	char *(*duckdb_value_to_string)(duckdb_value value);
	// New value functions that are added

	duckdb_value (*duckdb_create_map_value)(duckdb_logical_type map_type, duckdb_value *keys, duckdb_value *values,
	                                        idx_t entry_count);
	duckdb_value (*duckdb_create_union_value)(duckdb_logical_type union_type, idx_t tag_index, duckdb_value value);
	// API to create and manipulate vector types

	duckdb_vector (*duckdb_create_vector)(duckdb_logical_type type, idx_t capacity);
	void (*duckdb_destroy_vector)(duckdb_vector *vector);
	void (*duckdb_slice_vector)(duckdb_vector vector, duckdb_selection_vector sel, idx_t len);
	void (*duckdb_vector_reference_value)(duckdb_vector vector, duckdb_value value);
	void (*duckdb_vector_reference_vector)(duckdb_vector to_vector, duckdb_vector from_vector);
	duckdb_selection_vector (*duckdb_create_selection_vector)(idx_t size);
	void (*duckdb_destroy_selection_vector)(duckdb_selection_vector sel);
	sel_t *(*duckdb_selection_vector_get_data_ptr)(duckdb_selection_vector sel);
	void (*duckdb_vector_copy_sel)(duckdb_vector src, duckdb_vector dst, duckdb_selection_vector sel, idx_t src_count,
	                               idx_t src_offset, idx_t dst_offset);
} duckdb_ext_api_v1;

//===--------------------------------------------------------------------===//
// Struct Create Method
//===--------------------------------------------------------------------===//
inline duckdb_ext_api_v1 CreateAPIv1() {
	duckdb_ext_api_v1 result;
	result.duckdb_open = duckdb_open;
	result.duckdb_open_ext = duckdb_open_ext;
	result.duckdb_close = duckdb_close;
	result.duckdb_connect = duckdb_connect;
	result.duckdb_interrupt = duckdb_interrupt;
	result.duckdb_query_progress = duckdb_query_progress;
	result.duckdb_disconnect = duckdb_disconnect;
	result.duckdb_library_version = duckdb_library_version;
	result.duckdb_create_config = duckdb_create_config;
	result.duckdb_config_count = duckdb_config_count;
	result.duckdb_get_config_flag = duckdb_get_config_flag;
	result.duckdb_set_config = duckdb_set_config;
	result.duckdb_destroy_config = duckdb_destroy_config;
	result.duckdb_query = duckdb_query;
	result.duckdb_destroy_result = duckdb_destroy_result;
	result.duckdb_column_name = duckdb_column_name;
	result.duckdb_column_type = duckdb_column_type;
	result.duckdb_result_statement_type = duckdb_result_statement_type;
	result.duckdb_column_logical_type = duckdb_column_logical_type;
	result.duckdb_column_count = duckdb_column_count;
	result.duckdb_rows_changed = duckdb_rows_changed;
	result.duckdb_result_error = duckdb_result_error;
	result.duckdb_result_error_type = duckdb_result_error_type;
	result.duckdb_result_return_type = duckdb_result_return_type;
	result.duckdb_malloc = duckdb_malloc;
	result.duckdb_free = duckdb_free;
	result.duckdb_vector_size = duckdb_vector_size;
	result.duckdb_string_is_inlined = duckdb_string_is_inlined;
	result.duckdb_string_t_length = duckdb_string_t_length;
	result.duckdb_string_t_data = duckdb_string_t_data;
	result.duckdb_from_date = duckdb_from_date;
	result.duckdb_to_date = duckdb_to_date;
	result.duckdb_is_finite_date = duckdb_is_finite_date;
	result.duckdb_from_time = duckdb_from_time;
	result.duckdb_create_time_tz = duckdb_create_time_tz;
	result.duckdb_from_time_tz = duckdb_from_time_tz;
	result.duckdb_to_time = duckdb_to_time;
	result.duckdb_from_timestamp = duckdb_from_timestamp;
	result.duckdb_to_timestamp = duckdb_to_timestamp;
	result.duckdb_is_finite_timestamp = duckdb_is_finite_timestamp;
	result.duckdb_hugeint_to_double = duckdb_hugeint_to_double;
	result.duckdb_double_to_hugeint = duckdb_double_to_hugeint;
	result.duckdb_uhugeint_to_double = duckdb_uhugeint_to_double;
	result.duckdb_double_to_uhugeint = duckdb_double_to_uhugeint;
	result.duckdb_double_to_decimal = duckdb_double_to_decimal;
	result.duckdb_decimal_to_double = duckdb_decimal_to_double;
	result.duckdb_prepare = duckdb_prepare;
	result.duckdb_destroy_prepare = duckdb_destroy_prepare;
	result.duckdb_prepare_error = duckdb_prepare_error;
	result.duckdb_nparams = duckdb_nparams;
	result.duckdb_parameter_name = duckdb_parameter_name;
	result.duckdb_param_type = duckdb_param_type;
	result.duckdb_param_logical_type = duckdb_param_logical_type;
	result.duckdb_clear_bindings = duckdb_clear_bindings;
	result.duckdb_prepared_statement_type = duckdb_prepared_statement_type;
	result.duckdb_bind_value = duckdb_bind_value;
	result.duckdb_bind_parameter_index = duckdb_bind_parameter_index;
	result.duckdb_bind_boolean = duckdb_bind_boolean;
	result.duckdb_bind_int8 = duckdb_bind_int8;
	result.duckdb_bind_int16 = duckdb_bind_int16;
	result.duckdb_bind_int32 = duckdb_bind_int32;
	result.duckdb_bind_int64 = duckdb_bind_int64;
	result.duckdb_bind_hugeint = duckdb_bind_hugeint;
	result.duckdb_bind_uhugeint = duckdb_bind_uhugeint;
	result.duckdb_bind_decimal = duckdb_bind_decimal;
	result.duckdb_bind_uint8 = duckdb_bind_uint8;
	result.duckdb_bind_uint16 = duckdb_bind_uint16;
	result.duckdb_bind_uint32 = duckdb_bind_uint32;
	result.duckdb_bind_uint64 = duckdb_bind_uint64;
	result.duckdb_bind_float = duckdb_bind_float;
	result.duckdb_bind_double = duckdb_bind_double;
	result.duckdb_bind_date = duckdb_bind_date;
	result.duckdb_bind_time = duckdb_bind_time;
	result.duckdb_bind_timestamp = duckdb_bind_timestamp;
	result.duckdb_bind_timestamp_tz = duckdb_bind_timestamp_tz;
	result.duckdb_bind_interval = duckdb_bind_interval;
	result.duckdb_bind_varchar = duckdb_bind_varchar;
	result.duckdb_bind_varchar_length = duckdb_bind_varchar_length;
	result.duckdb_bind_blob = duckdb_bind_blob;
	result.duckdb_bind_null = duckdb_bind_null;
	result.duckdb_execute_prepared = duckdb_execute_prepared;
	result.duckdb_extract_statements = duckdb_extract_statements;
	result.duckdb_prepare_extracted_statement = duckdb_prepare_extracted_statement;
	result.duckdb_extract_statements_error = duckdb_extract_statements_error;
	result.duckdb_destroy_extracted = duckdb_destroy_extracted;
	result.duckdb_pending_prepared = duckdb_pending_prepared;
	result.duckdb_destroy_pending = duckdb_destroy_pending;
	result.duckdb_pending_error = duckdb_pending_error;
	result.duckdb_pending_execute_task = duckdb_pending_execute_task;
	result.duckdb_pending_execute_check_state = duckdb_pending_execute_check_state;
	result.duckdb_execute_pending = duckdb_execute_pending;
	result.duckdb_pending_execution_is_finished = duckdb_pending_execution_is_finished;
	result.duckdb_destroy_value = duckdb_destroy_value;
	result.duckdb_create_varchar = duckdb_create_varchar;
	result.duckdb_create_varchar_length = duckdb_create_varchar_length;
	result.duckdb_create_bool = duckdb_create_bool;
	result.duckdb_create_int8 = duckdb_create_int8;
	result.duckdb_create_uint8 = duckdb_create_uint8;
	result.duckdb_create_int16 = duckdb_create_int16;
	result.duckdb_create_uint16 = duckdb_create_uint16;
	result.duckdb_create_int32 = duckdb_create_int32;
	result.duckdb_create_uint32 = duckdb_create_uint32;
	result.duckdb_create_uint64 = duckdb_create_uint64;
	result.duckdb_create_int64 = duckdb_create_int64;
	result.duckdb_create_hugeint = duckdb_create_hugeint;
	result.duckdb_create_uhugeint = duckdb_create_uhugeint;
	result.duckdb_create_float = duckdb_create_float;
	result.duckdb_create_double = duckdb_create_double;
	result.duckdb_create_date = duckdb_create_date;
	result.duckdb_create_time = duckdb_create_time;
	result.duckdb_create_time_tz_value = duckdb_create_time_tz_value;
	result.duckdb_create_timestamp = duckdb_create_timestamp;
	result.duckdb_create_interval = duckdb_create_interval;
	result.duckdb_create_blob = duckdb_create_blob;
	result.duckdb_create_varint = duckdb_create_varint;
	result.duckdb_create_decimal = duckdb_create_decimal;
	result.duckdb_create_bit = duckdb_create_bit;
	result.duckdb_create_uuid = duckdb_create_uuid;
	result.duckdb_get_bool = duckdb_get_bool;
	result.duckdb_get_int8 = duckdb_get_int8;
	result.duckdb_get_uint8 = duckdb_get_uint8;
	result.duckdb_get_int16 = duckdb_get_int16;
	result.duckdb_get_uint16 = duckdb_get_uint16;
	result.duckdb_get_int32 = duckdb_get_int32;
	result.duckdb_get_uint32 = duckdb_get_uint32;
	result.duckdb_get_int64 = duckdb_get_int64;
	result.duckdb_get_uint64 = duckdb_get_uint64;
	result.duckdb_get_hugeint = duckdb_get_hugeint;
	result.duckdb_get_uhugeint = duckdb_get_uhugeint;
	result.duckdb_get_float = duckdb_get_float;
	result.duckdb_get_double = duckdb_get_double;
	result.duckdb_get_date = duckdb_get_date;
	result.duckdb_get_time = duckdb_get_time;
	result.duckdb_get_time_tz = duckdb_get_time_tz;
	result.duckdb_get_timestamp = duckdb_get_timestamp;
	result.duckdb_get_interval = duckdb_get_interval;
	result.duckdb_get_value_type = duckdb_get_value_type;
	result.duckdb_get_blob = duckdb_get_blob;
	result.duckdb_get_varint = duckdb_get_varint;
	result.duckdb_get_decimal = duckdb_get_decimal;
	result.duckdb_get_bit = duckdb_get_bit;
	result.duckdb_get_uuid = duckdb_get_uuid;
	result.duckdb_get_varchar = duckdb_get_varchar;
	result.duckdb_create_struct_value = duckdb_create_struct_value;
	result.duckdb_create_list_value = duckdb_create_list_value;
	result.duckdb_create_array_value = duckdb_create_array_value;
	result.duckdb_get_map_size = duckdb_get_map_size;
	result.duckdb_get_map_key = duckdb_get_map_key;
	result.duckdb_get_map_value = duckdb_get_map_value;
	result.duckdb_is_null_value = duckdb_is_null_value;
	result.duckdb_create_null_value = duckdb_create_null_value;
	result.duckdb_get_list_size = duckdb_get_list_size;
	result.duckdb_get_list_child = duckdb_get_list_child;
	result.duckdb_create_enum_value = duckdb_create_enum_value;
	result.duckdb_get_enum_value = duckdb_get_enum_value;
	result.duckdb_get_struct_child = duckdb_get_struct_child;
	result.duckdb_create_logical_type = duckdb_create_logical_type;
	result.duckdb_logical_type_get_alias = duckdb_logical_type_get_alias;
	result.duckdb_logical_type_set_alias = duckdb_logical_type_set_alias;
	result.duckdb_create_list_type = duckdb_create_list_type;
	result.duckdb_create_array_type = duckdb_create_array_type;
	result.duckdb_create_map_type = duckdb_create_map_type;
	result.duckdb_create_union_type = duckdb_create_union_type;
	result.duckdb_create_struct_type = duckdb_create_struct_type;
	result.duckdb_create_enum_type = duckdb_create_enum_type;
	result.duckdb_create_decimal_type = duckdb_create_decimal_type;
	result.duckdb_get_type_id = duckdb_get_type_id;
	result.duckdb_decimal_width = duckdb_decimal_width;
	result.duckdb_decimal_scale = duckdb_decimal_scale;
	result.duckdb_decimal_internal_type = duckdb_decimal_internal_type;
	result.duckdb_enum_internal_type = duckdb_enum_internal_type;
	result.duckdb_enum_dictionary_size = duckdb_enum_dictionary_size;
	result.duckdb_enum_dictionary_value = duckdb_enum_dictionary_value;
	result.duckdb_list_type_child_type = duckdb_list_type_child_type;
	result.duckdb_array_type_child_type = duckdb_array_type_child_type;
	result.duckdb_array_type_array_size = duckdb_array_type_array_size;
	result.duckdb_map_type_key_type = duckdb_map_type_key_type;
	result.duckdb_map_type_value_type = duckdb_map_type_value_type;
	result.duckdb_struct_type_child_count = duckdb_struct_type_child_count;
	result.duckdb_struct_type_child_name = duckdb_struct_type_child_name;
	result.duckdb_struct_type_child_type = duckdb_struct_type_child_type;
	result.duckdb_union_type_member_count = duckdb_union_type_member_count;
	result.duckdb_union_type_member_name = duckdb_union_type_member_name;
	result.duckdb_union_type_member_type = duckdb_union_type_member_type;
	result.duckdb_destroy_logical_type = duckdb_destroy_logical_type;
	result.duckdb_register_logical_type = duckdb_register_logical_type;
	result.duckdb_create_data_chunk = duckdb_create_data_chunk;
	result.duckdb_destroy_data_chunk = duckdb_destroy_data_chunk;
	result.duckdb_data_chunk_reset = duckdb_data_chunk_reset;
	result.duckdb_data_chunk_get_column_count = duckdb_data_chunk_get_column_count;
	result.duckdb_data_chunk_get_vector = duckdb_data_chunk_get_vector;
	result.duckdb_data_chunk_get_size = duckdb_data_chunk_get_size;
	result.duckdb_data_chunk_set_size = duckdb_data_chunk_set_size;
	result.duckdb_vector_get_column_type = duckdb_vector_get_column_type;
	result.duckdb_vector_get_data = duckdb_vector_get_data;
	result.duckdb_vector_get_validity = duckdb_vector_get_validity;
	result.duckdb_vector_ensure_validity_writable = duckdb_vector_ensure_validity_writable;
	result.duckdb_vector_assign_string_element = duckdb_vector_assign_string_element;
	result.duckdb_vector_assign_string_element_len = duckdb_vector_assign_string_element_len;
	result.duckdb_list_vector_get_child = duckdb_list_vector_get_child;
	result.duckdb_list_vector_get_size = duckdb_list_vector_get_size;
	result.duckdb_list_vector_set_size = duckdb_list_vector_set_size;
	result.duckdb_list_vector_reserve = duckdb_list_vector_reserve;
	result.duckdb_struct_vector_get_child = duckdb_struct_vector_get_child;
	result.duckdb_array_vector_get_child = duckdb_array_vector_get_child;
	result.duckdb_validity_row_is_valid = duckdb_validity_row_is_valid;
	result.duckdb_validity_set_row_validity = duckdb_validity_set_row_validity;
	result.duckdb_validity_set_row_invalid = duckdb_validity_set_row_invalid;
	result.duckdb_validity_set_row_valid = duckdb_validity_set_row_valid;
	result.duckdb_create_scalar_function = duckdb_create_scalar_function;
	result.duckdb_destroy_scalar_function = duckdb_destroy_scalar_function;
	result.duckdb_scalar_function_set_name = duckdb_scalar_function_set_name;
	result.duckdb_scalar_function_set_varargs = duckdb_scalar_function_set_varargs;
	result.duckdb_scalar_function_set_special_handling = duckdb_scalar_function_set_special_handling;
	result.duckdb_scalar_function_set_volatile = duckdb_scalar_function_set_volatile;
	result.duckdb_scalar_function_add_parameter = duckdb_scalar_function_add_parameter;
	result.duckdb_scalar_function_set_return_type = duckdb_scalar_function_set_return_type;
	result.duckdb_scalar_function_set_extra_info = duckdb_scalar_function_set_extra_info;
	result.duckdb_scalar_function_set_function = duckdb_scalar_function_set_function;
	result.duckdb_register_scalar_function = duckdb_register_scalar_function;
	result.duckdb_scalar_function_get_extra_info = duckdb_scalar_function_get_extra_info;
	result.duckdb_scalar_function_set_error = duckdb_scalar_function_set_error;
	result.duckdb_create_scalar_function_set = duckdb_create_scalar_function_set;
	result.duckdb_destroy_scalar_function_set = duckdb_destroy_scalar_function_set;
	result.duckdb_add_scalar_function_to_set = duckdb_add_scalar_function_to_set;
	result.duckdb_register_scalar_function_set = duckdb_register_scalar_function_set;
	result.duckdb_create_aggregate_function = duckdb_create_aggregate_function;
	result.duckdb_destroy_aggregate_function = duckdb_destroy_aggregate_function;
	result.duckdb_aggregate_function_set_name = duckdb_aggregate_function_set_name;
	result.duckdb_aggregate_function_add_parameter = duckdb_aggregate_function_add_parameter;
	result.duckdb_aggregate_function_set_return_type = duckdb_aggregate_function_set_return_type;
	result.duckdb_aggregate_function_set_functions = duckdb_aggregate_function_set_functions;
	result.duckdb_aggregate_function_set_destructor = duckdb_aggregate_function_set_destructor;
	result.duckdb_register_aggregate_function = duckdb_register_aggregate_function;
	result.duckdb_aggregate_function_set_special_handling = duckdb_aggregate_function_set_special_handling;
	result.duckdb_aggregate_function_set_extra_info = duckdb_aggregate_function_set_extra_info;
	result.duckdb_aggregate_function_get_extra_info = duckdb_aggregate_function_get_extra_info;
	result.duckdb_aggregate_function_set_error = duckdb_aggregate_function_set_error;
	result.duckdb_create_aggregate_function_set = duckdb_create_aggregate_function_set;
	result.duckdb_destroy_aggregate_function_set = duckdb_destroy_aggregate_function_set;
	result.duckdb_add_aggregate_function_to_set = duckdb_add_aggregate_function_to_set;
	result.duckdb_register_aggregate_function_set = duckdb_register_aggregate_function_set;
	result.duckdb_create_table_function = duckdb_create_table_function;
	result.duckdb_destroy_table_function = duckdb_destroy_table_function;
	result.duckdb_table_function_set_name = duckdb_table_function_set_name;
	result.duckdb_table_function_add_parameter = duckdb_table_function_add_parameter;
	result.duckdb_table_function_add_named_parameter = duckdb_table_function_add_named_parameter;
	result.duckdb_table_function_set_extra_info = duckdb_table_function_set_extra_info;
	result.duckdb_table_function_set_bind = duckdb_table_function_set_bind;
	result.duckdb_table_function_set_init = duckdb_table_function_set_init;
	result.duckdb_table_function_set_local_init = duckdb_table_function_set_local_init;
	result.duckdb_table_function_set_function = duckdb_table_function_set_function;
	result.duckdb_table_function_supports_projection_pushdown = duckdb_table_function_supports_projection_pushdown;
	result.duckdb_register_table_function = duckdb_register_table_function;
	result.duckdb_bind_get_extra_info = duckdb_bind_get_extra_info;
	result.duckdb_bind_add_result_column = duckdb_bind_add_result_column;
	result.duckdb_bind_get_parameter_count = duckdb_bind_get_parameter_count;
	result.duckdb_bind_get_parameter = duckdb_bind_get_parameter;
	result.duckdb_bind_get_named_parameter = duckdb_bind_get_named_parameter;
	result.duckdb_bind_set_bind_data = duckdb_bind_set_bind_data;
	result.duckdb_bind_set_cardinality = duckdb_bind_set_cardinality;
	result.duckdb_bind_set_error = duckdb_bind_set_error;
	result.duckdb_init_get_extra_info = duckdb_init_get_extra_info;
	result.duckdb_init_get_bind_data = duckdb_init_get_bind_data;
	result.duckdb_init_set_init_data = duckdb_init_set_init_data;
	result.duckdb_init_get_column_count = duckdb_init_get_column_count;
	result.duckdb_init_get_column_index = duckdb_init_get_column_index;
	result.duckdb_init_set_max_threads = duckdb_init_set_max_threads;
	result.duckdb_init_set_error = duckdb_init_set_error;
	result.duckdb_function_get_extra_info = duckdb_function_get_extra_info;
	result.duckdb_function_get_bind_data = duckdb_function_get_bind_data;
	result.duckdb_function_get_init_data = duckdb_function_get_init_data;
	result.duckdb_function_get_local_init_data = duckdb_function_get_local_init_data;
	result.duckdb_function_set_error = duckdb_function_set_error;
	result.duckdb_add_replacement_scan = duckdb_add_replacement_scan;
	result.duckdb_replacement_scan_set_function_name = duckdb_replacement_scan_set_function_name;
	result.duckdb_replacement_scan_add_parameter = duckdb_replacement_scan_add_parameter;
	result.duckdb_replacement_scan_set_error = duckdb_replacement_scan_set_error;
	result.duckdb_profiling_info_get_metrics = duckdb_profiling_info_get_metrics;
	result.duckdb_profiling_info_get_child_count = duckdb_profiling_info_get_child_count;
	result.duckdb_profiling_info_get_child = duckdb_profiling_info_get_child;
	result.duckdb_appender_create = duckdb_appender_create;
	result.duckdb_appender_create_ext = duckdb_appender_create_ext;
	result.duckdb_appender_column_count = duckdb_appender_column_count;
	result.duckdb_appender_column_type = duckdb_appender_column_type;
	result.duckdb_appender_error = duckdb_appender_error;
	result.duckdb_appender_flush = duckdb_appender_flush;
	result.duckdb_appender_close = duckdb_appender_close;
	result.duckdb_appender_destroy = duckdb_appender_destroy;
	result.duckdb_appender_add_column = duckdb_appender_add_column;
	result.duckdb_appender_clear_columns = duckdb_appender_clear_columns;
	result.duckdb_append_data_chunk = duckdb_append_data_chunk;
	result.duckdb_table_description_create = duckdb_table_description_create;
	result.duckdb_table_description_create_ext = duckdb_table_description_create_ext;
	result.duckdb_table_description_destroy = duckdb_table_description_destroy;
	result.duckdb_table_description_error = duckdb_table_description_error;
	result.duckdb_column_has_default = duckdb_column_has_default;
	result.duckdb_table_description_get_column_name = duckdb_table_description_get_column_name;
	result.duckdb_execute_tasks = duckdb_execute_tasks;
	result.duckdb_create_task_state = duckdb_create_task_state;
	result.duckdb_execute_tasks_state = duckdb_execute_tasks_state;
	result.duckdb_execute_n_tasks_state = duckdb_execute_n_tasks_state;
	result.duckdb_finish_execution = duckdb_finish_execution;
	result.duckdb_task_state_is_finished = duckdb_task_state_is_finished;
	result.duckdb_destroy_task_state = duckdb_destroy_task_state;
	result.duckdb_execution_is_finished = duckdb_execution_is_finished;
	result.duckdb_fetch_chunk = duckdb_fetch_chunk;
	result.duckdb_create_cast_function = duckdb_create_cast_function;
	result.duckdb_cast_function_set_source_type = duckdb_cast_function_set_source_type;
	result.duckdb_cast_function_set_target_type = duckdb_cast_function_set_target_type;
	result.duckdb_cast_function_set_implicit_cast_cost = duckdb_cast_function_set_implicit_cast_cost;
	result.duckdb_cast_function_set_function = duckdb_cast_function_set_function;
	result.duckdb_cast_function_set_extra_info = duckdb_cast_function_set_extra_info;
	result.duckdb_cast_function_get_extra_info = duckdb_cast_function_get_extra_info;
	result.duckdb_cast_function_get_cast_mode = duckdb_cast_function_get_cast_mode;
	result.duckdb_cast_function_set_error = duckdb_cast_function_set_error;
	result.duckdb_cast_function_set_row_error = duckdb_cast_function_set_row_error;
	result.duckdb_register_cast_function = duckdb_register_cast_function;
	result.duckdb_destroy_cast_function = duckdb_destroy_cast_function;
	result.duckdb_is_finite_timestamp_s = duckdb_is_finite_timestamp_s;
	result.duckdb_is_finite_timestamp_ms = duckdb_is_finite_timestamp_ms;
	result.duckdb_is_finite_timestamp_ns = duckdb_is_finite_timestamp_ns;
	result.duckdb_create_timestamp_tz = duckdb_create_timestamp_tz;
	result.duckdb_create_timestamp_s = duckdb_create_timestamp_s;
	result.duckdb_create_timestamp_ms = duckdb_create_timestamp_ms;
	result.duckdb_create_timestamp_ns = duckdb_create_timestamp_ns;
	result.duckdb_get_timestamp_tz = duckdb_get_timestamp_tz;
	result.duckdb_get_timestamp_s = duckdb_get_timestamp_s;
	result.duckdb_get_timestamp_ms = duckdb_get_timestamp_ms;
	result.duckdb_get_timestamp_ns = duckdb_get_timestamp_ns;
	result.duckdb_append_value = duckdb_append_value;
	result.duckdb_get_profiling_info = duckdb_get_profiling_info;
	result.duckdb_profiling_info_get_value = duckdb_profiling_info_get_value;
	result.duckdb_appender_begin_row = duckdb_appender_begin_row;
	result.duckdb_appender_end_row = duckdb_appender_end_row;
	result.duckdb_append_default = duckdb_append_default;
	result.duckdb_append_bool = duckdb_append_bool;
	result.duckdb_append_int8 = duckdb_append_int8;
	result.duckdb_append_int16 = duckdb_append_int16;
	result.duckdb_append_int32 = duckdb_append_int32;
	result.duckdb_append_int64 = duckdb_append_int64;
	result.duckdb_append_hugeint = duckdb_append_hugeint;
	result.duckdb_append_uint8 = duckdb_append_uint8;
	result.duckdb_append_uint16 = duckdb_append_uint16;
	result.duckdb_append_uint32 = duckdb_append_uint32;
	result.duckdb_append_uint64 = duckdb_append_uint64;
	result.duckdb_append_uhugeint = duckdb_append_uhugeint;
	result.duckdb_append_float = duckdb_append_float;
	result.duckdb_append_double = duckdb_append_double;
	result.duckdb_append_date = duckdb_append_date;
	result.duckdb_append_time = duckdb_append_time;
	result.duckdb_append_timestamp = duckdb_append_timestamp;
	result.duckdb_append_interval = duckdb_append_interval;
	result.duckdb_append_varchar = duckdb_append_varchar;
	result.duckdb_append_varchar_length = duckdb_append_varchar_length;
	result.duckdb_append_blob = duckdb_append_blob;
	result.duckdb_append_null = duckdb_append_null;
	result.duckdb_row_count = duckdb_row_count;
	result.duckdb_column_data = duckdb_column_data;
	result.duckdb_nullmask_data = duckdb_nullmask_data;
	result.duckdb_result_get_chunk = duckdb_result_get_chunk;
	result.duckdb_result_is_streaming = duckdb_result_is_streaming;
	result.duckdb_result_chunk_count = duckdb_result_chunk_count;
	result.duckdb_value_boolean = duckdb_value_boolean;
	result.duckdb_value_int8 = duckdb_value_int8;
	result.duckdb_value_int16 = duckdb_value_int16;
	result.duckdb_value_int32 = duckdb_value_int32;
	result.duckdb_value_int64 = duckdb_value_int64;
	result.duckdb_value_hugeint = duckdb_value_hugeint;
	result.duckdb_value_uhugeint = duckdb_value_uhugeint;
	result.duckdb_value_decimal = duckdb_value_decimal;
	result.duckdb_value_uint8 = duckdb_value_uint8;
	result.duckdb_value_uint16 = duckdb_value_uint16;
	result.duckdb_value_uint32 = duckdb_value_uint32;
	result.duckdb_value_uint64 = duckdb_value_uint64;
	result.duckdb_value_float = duckdb_value_float;
	result.duckdb_value_double = duckdb_value_double;
	result.duckdb_value_date = duckdb_value_date;
	result.duckdb_value_time = duckdb_value_time;
	result.duckdb_value_timestamp = duckdb_value_timestamp;
	result.duckdb_value_interval = duckdb_value_interval;
	result.duckdb_value_varchar = duckdb_value_varchar;
	result.duckdb_value_string = duckdb_value_string;
	result.duckdb_value_varchar_internal = duckdb_value_varchar_internal;
	result.duckdb_value_string_internal = duckdb_value_string_internal;
	result.duckdb_value_blob = duckdb_value_blob;
	result.duckdb_value_is_null = duckdb_value_is_null;
	result.duckdb_execute_prepared_streaming = duckdb_execute_prepared_streaming;
	result.duckdb_pending_prepared_streaming = duckdb_pending_prepared_streaming;
	result.duckdb_query_arrow = duckdb_query_arrow;
	result.duckdb_query_arrow_schema = duckdb_query_arrow_schema;
	result.duckdb_prepared_arrow_schema = duckdb_prepared_arrow_schema;
	result.duckdb_result_arrow_array = duckdb_result_arrow_array;
	result.duckdb_query_arrow_array = duckdb_query_arrow_array;
	result.duckdb_arrow_column_count = duckdb_arrow_column_count;
	result.duckdb_arrow_row_count = duckdb_arrow_row_count;
	result.duckdb_arrow_rows_changed = duckdb_arrow_rows_changed;
	result.duckdb_query_arrow_error = duckdb_query_arrow_error;
	result.duckdb_destroy_arrow = duckdb_destroy_arrow;
	result.duckdb_destroy_arrow_stream = duckdb_destroy_arrow_stream;
	result.duckdb_execute_prepared_arrow = duckdb_execute_prepared_arrow;
	result.duckdb_arrow_scan = duckdb_arrow_scan;
	result.duckdb_arrow_array_scan = duckdb_arrow_array_scan;
	result.duckdb_stream_fetch_chunk = duckdb_stream_fetch_chunk;
	result.duckdb_create_instance_cache = duckdb_create_instance_cache;
	result.duckdb_get_or_create_from_cache = duckdb_get_or_create_from_cache;
	result.duckdb_destroy_instance_cache = duckdb_destroy_instance_cache;
	result.duckdb_append_default_to_chunk = duckdb_append_default_to_chunk;
	result.duckdb_appender_error_data = duckdb_appender_error_data;
	result.duckdb_to_arrow_schema = duckdb_to_arrow_schema;
	result.duckdb_data_chunk_to_arrow = duckdb_data_chunk_to_arrow;
	result.duckdb_schema_from_arrow = duckdb_schema_from_arrow;
	result.duckdb_data_chunk_from_arrow = duckdb_data_chunk_from_arrow;
	result.duckdb_destroy_arrow_converted_schema = duckdb_destroy_arrow_converted_schema;
	result.duckdb_create_error_data = duckdb_create_error_data;
	result.duckdb_destroy_error_data = duckdb_destroy_error_data;
	result.duckdb_error_data_error_type = duckdb_error_data_error_type;
	result.duckdb_error_data_message = duckdb_error_data_message;
	result.duckdb_error_data_has_error = duckdb_error_data_has_error;
	result.duckdb_destroy_expression = duckdb_destroy_expression;
	result.duckdb_expression_return_type = duckdb_expression_return_type;
	result.duckdb_expression_is_foldable = duckdb_expression_is_foldable;
	result.duckdb_expression_fold = duckdb_expression_fold;
	result.duckdb_client_context_get_connection_id = duckdb_client_context_get_connection_id;
	result.duckdb_destroy_client_context = duckdb_destroy_client_context;
	result.duckdb_connection_get_client_context = duckdb_connection_get_client_context;
	result.duckdb_get_table_names = duckdb_get_table_names;
	result.duckdb_connection_get_arrow_options = duckdb_connection_get_arrow_options;
	result.duckdb_destroy_arrow_options = duckdb_destroy_arrow_options;
	result.duckdb_result_get_arrow_options = duckdb_result_get_arrow_options;
	result.duckdb_scalar_function_set_bind = duckdb_scalar_function_set_bind;
	result.duckdb_scalar_function_bind_set_error = duckdb_scalar_function_bind_set_error;
	result.duckdb_scalar_function_get_client_context = duckdb_scalar_function_get_client_context;
	result.duckdb_scalar_function_set_bind_data = duckdb_scalar_function_set_bind_data;
	result.duckdb_scalar_function_get_bind_data = duckdb_scalar_function_get_bind_data;
	result.duckdb_scalar_function_bind_get_extra_info = duckdb_scalar_function_bind_get_extra_info;
	result.duckdb_scalar_function_bind_get_argument_count = duckdb_scalar_function_bind_get_argument_count;
	result.duckdb_scalar_function_bind_get_argument = duckdb_scalar_function_bind_get_argument;
	result.duckdb_value_to_string = duckdb_value_to_string;
	result.duckdb_create_map_value = duckdb_create_map_value;
	result.duckdb_create_union_value = duckdb_create_union_value;
	result.duckdb_create_vector = duckdb_create_vector;
	result.duckdb_destroy_vector = duckdb_destroy_vector;
	result.duckdb_slice_vector = duckdb_slice_vector;
	result.duckdb_vector_reference_value = duckdb_vector_reference_value;
	result.duckdb_vector_reference_vector = duckdb_vector_reference_vector;
	result.duckdb_create_selection_vector = duckdb_create_selection_vector;
	result.duckdb_destroy_selection_vector = duckdb_destroy_selection_vector;
	result.duckdb_selection_vector_get_data_ptr = duckdb_selection_vector_get_data_ptr;
	result.duckdb_vector_copy_sel = duckdb_vector_copy_sel;
	return result;
}

#define DUCKDB_EXTENSION_API_VERSION_MAJOR  1
#define DUCKDB_EXTENSION_API_VERSION_MINOR  2
#define DUCKDB_EXTENSION_API_VERSION_PATCH  0
#define DUCKDB_EXTENSION_API_VERSION_STRING "v1.2.0"

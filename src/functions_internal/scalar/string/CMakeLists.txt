add_library_unity(duckdb_func_internal_string_main OBJECT caseconvert.cpp)
set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:duckdb_func_internal_string_main>
    PARENT_SCOPE)

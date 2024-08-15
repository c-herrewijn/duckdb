add_subdirectory(regexp)
add_library_unity(duckdb_func_string_main OBJECT like.cpp regexp.cpp
                  substring.cpp)
set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:duckdb_func_string_main>
    PARENT_SCOPE)

add_subdirectory(regexp)
add_library_unity(
  duckdb_func_string_main
  OBJECT
  length.cpp
  like.cpp
  nfc_normalize.cpp
  regexp.cpp
  substring.cpp
  strip_accents.cpp
  contains.cpp)
set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:duckdb_func_string_main>
    PARENT_SCOPE)

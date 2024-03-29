
find_library(LLXGVAHWDB_BASE_LIB "llxgvahwdb")
set(LLIUREX_GVAHWDB_INCLUDE_DIRS "/usr/include/lliurex/gvahwdb/")
set(LLIUREX_GVAHWDB_LIBRARIES ${LLXGVAHWDB_BASE_LIB})

add_library(Lliurex::GvaHwdb SHARED IMPORTED)
set_target_properties(Lliurex::GvaHwdb PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${LLIUREX_GVAHWDB_INCLUDE_DIRS}
    INTERFACE_LINK_LIBRARIES "Lliurex::GvaHwdb"
    IMPORTED_LOCATION ${LLIUREX_GVAHWDB_LIBRARIES}
)

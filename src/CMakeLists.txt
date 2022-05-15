
find_package(PkgConfig REQUIRED)

add_library(llxgvahwdb SHARED libllxgvahwdb.c)
set_target_properties(llxgvahwdb PROPERTIES SOVERSION 1 VERSION "1.0.0")

add_executable(llx-gva-hwdb llxgvahwdb.c)
target_link_libraries(llx-gva-hwdb llxgvahwdb)

install(TARGETS llx-gva-hwdb RUNTIME DESTINATION bin)
install(TARGETS llxgvahwdb LIBRARY DESTINATION lib)
install(FILES "libllxgvahwdb.h" "hwdb.h"
    DESTINATION "include/lliurex/gvahwdb"
)

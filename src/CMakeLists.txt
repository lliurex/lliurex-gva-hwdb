
find_package(PkgConfig REQUIRED)
pkg_check_modules(SMBIOS REQUIRED libsmbios_c)

add_library(llxgvahwdb SHARED libllxgvahwdb.c)
target_link_libraries(llxgvahwdb ${SMBIOS_LIBRARIES})
set_target_properties(llxgvahwdb PROPERTIES SOVERSION 1 VERSION "1.0.0")

add_executable(llx-gva-hwdb llxgvahwdb.c)
target_link_libraries(llx-gva-hwdb llxgvahwdb)

install(TARGETS llx-gva-hwdb RUNTIME DESTINATION sbin)
install(TARGETS llxgvahwdb LIBRARY DESTINATION lib)

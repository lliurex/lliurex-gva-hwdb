cmake_minimum_required(VERSION 3.0)
project(lliurex-gva-hwdb)

add_subdirectory(src)

install(FILES "LliurexGvaHwdbConfig.cmake"
    DESTINATION "lib/cmake/LliurexGvaHwdb"
)

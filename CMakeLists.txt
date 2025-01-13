cmake_minimum_required(VERSION 3.10)
project(lpb C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/3thrd)

find_package(PkgConfig)

pkg_check_modules(GIO REQUIRED gio-2.0)

include(src/src.cmake)

add_executable(lpd-daemon ${DAEMON_SRC} ${COMMON_SRC})
target_link_libraries(lpd-daemon PUBLIC ${GIO_LIBRARIES})
target_include_directories(lpd-daemon PUBLIC ${GIO_INCLUDE_DIRS})

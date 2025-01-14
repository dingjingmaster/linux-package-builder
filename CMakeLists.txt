cmake_minimum_required(VERSION 3.10)
project(lpb C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_definitions(-D QT_NO_KEYWORDS -D QT_MESSAGELOGCONTEXT
        -D INSTALL_DIR=\\"${INSTALL_DIR}\\"
        -D LPB_VERSION=\\"${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}\\")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/3thrd)

set(INSTALL_DIR "/usr/local/ldp")

find_package(PkgConfig)
find_package(Qt5 COMPONENTS Core Network REQUIRED)

pkg_check_modules(GIO REQUIRED gio-2.0)
pkg_check_modules(QT5 REQUIRED Qt5Core Qt5Network)

include(src/src.cmake)

add_executable(lpb-daemon ${DAEMON_SRC} ${COMMON_SRC})
target_compile_options(lpb-daemon PUBLIC -fPIC)
target_link_libraries(lpb-daemon PUBLIC ${GIO_LIBRARIES} ${QT5_LIBRARIES})
target_include_directories(lpb-daemon PUBLIC ${GIO_INCLUDE_DIRS} ${QT5_INCLUDE_DIRS})
target_compile_definitions(lpb-daemon PUBLIC -D C_LOG_TAG=\"lpb-daemon\" -D QAPPLICATIOOOOON_CLASS=QCoreApplication)


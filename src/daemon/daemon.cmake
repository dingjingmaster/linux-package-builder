file(GLOB DAEMON_SRC
        ${CMAKE_SOURCE_DIR}/src/daemon/main.cc

        ${CMAKE_SOURCE_DIR}/src/daemon/daemon.h
        ${CMAKE_SOURCE_DIR}/src/daemon/daemon.cc

        ${CMAKE_SOURCE_DIR}/src/daemon/server-rpc.h
        ${CMAKE_SOURCE_DIR}/src/daemon/server-rpc.cc
)

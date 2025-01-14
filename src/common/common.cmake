file(GLOB COMMON_SRC
        ${CMAKE_SOURCE_DIR}/src/common/log.c
        ${CMAKE_SOURCE_DIR}/src/common/log.h

        ${CMAKE_SOURCE_DIR}/src/common/qlog.h
        ${CMAKE_SOURCE_DIR}/src/common/qlog.cc

        ${CMAKE_SOURCE_DIR}/src/common/types.h

        ${CMAKE_SOURCE_DIR}/src/common/storage.h
        ${CMAKE_SOURCE_DIR}/src/common/storage.cc

        ${CMAKE_SOURCE_DIR}/src/common/defines.h

        ${CMAKE_SOURCE_DIR}/3thrd/SingleApplication/SingleApplication

        ${CMAKE_SOURCE_DIR}/3thrd/SingleApplication/singleapplication.h
        ${CMAKE_SOURCE_DIR}/3thrd/SingleApplication/singleapplication.cpp

        ${CMAKE_SOURCE_DIR}/3thrd/SingleApplication/singleapplication_p.h
        ${CMAKE_SOURCE_DIR}/3thrd/SingleApplication/singleapplication_p.cpp
)

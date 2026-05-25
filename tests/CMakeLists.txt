CMAKE_MINIMUM_REQUIRED (VERSION 3.20)
PROJECT (simpw-tests)

INCLUDE (FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

SET (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET (MAIN_SRC_DIR ${CMAKE_SOURCE_DIR}/src)
SET (HEADERS_DIR ${CMAKE_SOURCE_DIR}/include/simpw)
SET (SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/SocketTest.cpp
        ${SRC_DIR}/SocketAddressTest.cpp
        # Main source dir
        ${MAIN_SRC_DIR}/Socket.cpp
        ${MAIN_SRC_DIR}/SocketAddress.cpp
    )

SET (HEADERS
        ${HEADERS_DIR}/Socket.h
        ${HEADERS_DIR}/SocketAddress.h
    )

ADD_EXECUTABLE (${PROJECT_NAME} ${SOURCES} ${HEADERS})
TARGET_LINK_LIBRARIES (
    ${PROJECT_NAME} PRIVATE 
        GTest::gtest
        GTest::gmock
)
TARGET_INCLUDE_DIRECTORIES (
    ${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/include/simpw
        ${CMAKE_CURRENT_SOURCE_DIR}
)

INCLUDE (GoogleTest)
gtest_discover_tests (${PROJECT_NAME})

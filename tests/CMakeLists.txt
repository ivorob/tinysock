CMAKE_MINIMUM_REQUIRED (VERSION 3.20)
PROJECT (simpw-tests)

INCLUDE (FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

SET (SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )

ADD_EXECUTABLE (${PROJECT_NAME} ${SOURCES})
TARGET_LINK_LIBRARIES (${PROJECT_NAME} PRIVATE GTest::gtest)


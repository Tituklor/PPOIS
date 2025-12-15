
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable(SetTests tests.cpp)
target_link_libraries(SetTests
        SetLib
        gtest
        gtest_main
)

target_include_directories(SetTests PRIVATE
        ${CMAKE_SOURCE_DIR}/Set
)

include(GoogleTest)
gtest_discover_tests(SetTests)

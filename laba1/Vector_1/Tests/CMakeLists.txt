project(Tests)

add_executable(Tests
        Vector3D_test.cpp
)

target_include_directories(Tests PRIVATE
        ${CMAKE_SOURCE_DIR}/Vector3D
)

target_link_libraries(Tests
        Vector3D
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)

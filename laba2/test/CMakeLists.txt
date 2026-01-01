# test/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

# === 1. Находим Google Test (если не подключен извне) ===
if(NOT TARGET gtest)
    # Предполагаем, что googletest лежит на уровень выше: ../googletest
    find_path(GTEST_INCLUDE_DIR gtest/gtest.h
            PATHS ${CMAKE_SOURCE_DIR}/../googletest/googletest/include
            NO_DEFAULT_PATH
    )
    if(NOT GTEST_INCLUDE_DIR)
        message(FATAL_ERROR "Google Test headers not found! Expected at: ${CMAKE_SOURCE_DIR}/../googletest/googletest/include")
    endif()

    # Собираем gtest как статическую библиотеку
    add_library(gtest STATIC
            ${CMAKE_SOURCE_DIR}/../googletest/googletest/src/gtest-all.cc
    )
    target_include_directories(gtest PUBLIC ${GTEST_INCLUDE_DIR})

    add_library(gtest_main STATIC
            ${CMAKE_SOURCE_DIR}/../googletest/googletest/src/gtest_main.cc
    )
    target_link_libraries(gtest_main gtest)
endif()

# === 2. Собираем библиотеку основного кода (из ../src) ===
file(GLOB_RECURSE SRC_FILES
        CONFIGURE_DEPENDS
        "../src/config/*.cpp"
        "../src/exceptions/*.cpp"
        "../src/core/*/*.cpp"
        "../src/membership/*.cpp"
        "../src/finance/*.cpp"
        "../src/schedule/*.cpp"
        "../src/facility/*.cpp"
        "../src/equipment/*.cpp"
        "../src/service/*.cpp"
        "../src/manager/*.cpp"
        "../src/server/*.cpp"
)

add_library(SportClubCore STATIC ${SRC_FILES})
target_include_directories(SportClubCore PUBLIC ${CMAKE_SOURCE_DIR}/../src)

# === 3. Тесты (только 10 ключевых) ===
set(TEST_SOURCES
        PersonTest.cpp
        MemberTest.cpp
        CoachTest.cpp
        MembershipPlanTest.cpp
        PaymentTest.cpp
        BookingTest.cpp
        FacilityTest.cpp
        EquipmentTest.cpp
        MemberManagerTest.cpp
        PaymentManagerTest.cpp
)

add_executable(runUnitTests ${TEST_SOURCES})

target_include_directories(runUnitTests PRIVATE
        ${CMAKE_SOURCE_DIR}/../src
        ${GTEST_INCLUDE_DIR}
)

target_link_libraries(runUnitTests
        SportClubCore
        gtest
        gtest_main
)

# Unix-only: pthread
if(UNIX AND NOT APPLE)
    target_link_libraries(runUnitTests pthread)
endif()

# === 4. Покрытие (только в Debug) ===
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(SportClubCore PRIVATE --coverage)
    target_link_options(SportClubCore PRIVATE --coverage)
    target_compile_options(runUnitTests PRIVATE --coverage)
    target_link_options(runUnitTests PRIVATE --coverage)
endif()

# === 5. Регистрация теста для ctest ===
include(CTest)
add_test(NAME UnitTests COMMAND runUnitTests)
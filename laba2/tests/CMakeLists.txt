# Тесты для sport_club_1 с Google Test
cmake_minimum_required(VERSION 3.16)
project(SportClub1Tests)

# Автоматически скачиваем GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Настраиваем пути к исходному проекту sport_club_1
add_library(sport_club_1_lib INTERFACE)
target_include_directories(sport_club_1_lib INTERFACE
        ../
        ../Enums
        ../Human
        ../Reception
        ../Room
        ../Schedule
        ../SM
        ../Shop
        ../Mirror
)

# Создаем исполняемый файл тестов
add_executable(sport_club_1_tests
        sport_club_1_tests.cpp
)

# Линкуем GoogleTest и наш проект
target_link_libraries(sport_club_1_tests
        PRIVATE
        GTest::gtest_main
        GTest::gmock_main
        sport_club_1_lib
)

# Регистрируем тесты для CTest
include(GoogleTest)
gtest_discover_tests(sport_club_1_tests)

# Поддержка C++17
target_compile_features(sport_club_1_tests PRIVATE cxx_std_17)

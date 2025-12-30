# Тесты для зон спортклуба с Google Test
cmake_minimum_required(VERSION 3.16)
project(SportClubZonesTests)

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
        ../changing_room_defs.h
        ../fitness_zone.h
        ../gym_zone.h
        ../pool_zone.h
        ../ring_zone.h
        ../sauna_zone.h
        ../scale_defs.h
)

# Создаем исполняемый файл тестов
add_executable(sport_club_zones_tests
        sport_club_zones_tests.cpp
)

# Линкуем GoogleTest и наш проект
target_link_libraries(sport_club_zones_tests
        PRIVATE
        GTest::gtest_main
        GTest::gmock_main
        sport_club_1_lib
)

# Регистрируем тесты для CTest
include(GoogleTest)
gtest_discover_tests(sport_club_zones_tests)

# Поддержка C++17
target_compile_features(sport_club_zones_tests PRIVATE cxx_std_17)

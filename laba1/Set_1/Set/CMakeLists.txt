add_library(SetLib STATIC Set.cpp Set.h)

target_include_directories(SetLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_compile_features(SetLib PUBLIC cxx_std_17)

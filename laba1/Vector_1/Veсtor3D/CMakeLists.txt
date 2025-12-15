project(Vector3D)

add_library(Vector3D
        Vector3D.cpp
        Vector3D.h
)

target_include_directories(Vector3D PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

cmake_minimum_required(VERSION 3.27)
project(vector_1)

set(CMAKE_CXX_STANDARD 17)

# 1. Подключаем GoogleTest
add_subdirectory(googletest-main)

# 2. Подключаем библиотеку Vector3D
add_subdirectory(Vector3D)

# 3. Подключаем тесты
add_subdirectory(Tests)


add_executable(vector_1 main.cpp)
target_link_libraries(vector_1 Vector3D)
target_include_directories(vector_1 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Vector3D
)

# 5. Включаем систему тестирования
enable_testing()


find_package(Doxygen)

if(DOXYGEN_FOUND)
    message(STATUS "Doxygen found: ${DOXYGEN_EXECUTABLE}")

    # Собираем все исходные файлы проекта
    file(GLOB_RECURSE ALL_SOURCE_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/*.h
            ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Vector3D/*.h
            ${CMAKE_CURRENT_SOURCE_DIR}/Vector3D/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Tests/*.cpp
    )

    # Настройки Doxygen
    set(DOXYGEN_PROJECT_NAME "Vector3D Library")
    set(DOXYGEN_PROJECT_NUMBER "1.0")
    set(DOXYGEN_PROJECT_BRIEF "Библиотека для работы с трехмерными векторами")
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/docs")
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_EXTRACT_PRIVATE YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_HIDE_UNDOC_MEMBERS NO)
    set(DOXYGEN_HIDE_UNDOC_CLASSES NO)
    set(DOXYGEN_HAVE_DOT YES)
    set(DOXYGEN_CALL_GRAPH YES)
    set(DOXYGEN_CALLER_GRAPH YES)
    set(DOXYGEN_OUTPUT_LANGUAGE "Russian")
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
    set(DOXYGEN_SOURCE_BROWSER YES)
    set(DOXYGEN_INLINE_SOURCES YES)
    set(DOXYGEN_STRIP_FROM_INC_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
    set(DOXYGEN_STRIP_FROM_PATH "${CMAKE_CURRENT_SOURCE_DIR}")


    doxygen_add_docs(
            vector_docs
            ${ALL_SOURCE_FILES}
            COMMENT "Generating documentation for Vector3D library"
    )


    add_custom_target(open_vector_docs
            COMMAND echo "Documentation generated at: ${CMAKE_BINARY_DIR}/docs/html/index.html"
            COMMAND start "${CMAKE_BINARY_DIR}/docs/html/index.html"
            DEPENDS vector_docs
            COMMENT "Opening documentation in browser"
    )

else()
    message(WARNING "Doxygen not found! Documentation will not be generated.")
endif()

cmake_minimum_required(VERSION 3.20)
project(Set)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Библиотека Set 
add_subdirectory(Set)

# Тесты 
add_subdirectory(test)

# Основное приложение
add_executable(SetApp main.cpp)
target_link_libraries(SetApp SetLib)


find_package(Doxygen REQUIRED dot)

if(DOXYGEN_FOUND)
   
    file(GLOB_RECURSE DOXYGEN_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/Set/*.h
            ${CMAKE_CURRENT_SOURCE_DIR}/Set/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/*.h
            ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    )

   
    set(DOXYGEN_INPUT "${DOXYGEN_SOURCES}")
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs")
    set(DOXYGEN_HTML_OUTPUT "html")
    set(DOXYGEN_GENERATE_HTML "YES")
    set(DOXYGEN_GENERATE_LATEX "NO")
    set(DOXYGEN_EXTRACT_ALL "YES")
    set(DOXYGEN_EXTRACT_PRIVATE "YES")
    set(DOXYGEN_EXTRACT_STATIC "YES")
    set(DOXYGEN_RECURSIVE "YES")
    set(DOXYGEN_HIDE_UNDOC_MEMBERS "NO")
    set(DOXYGEN_HIDE_UNDOC_CLASSES "NO")
    set(DOXYGEN_HAVE_DOT "YES")
    set(DOXYGEN_CALL_GRAPH "YES")
    set(DOXYGEN_CALLER_GRAPH "YES")
    set(DOXYGEN_UML_LOOK "YES")
    set(DOXYGEN_TEMPLATE_RELATIONS "YES")
    set(DOXYGEN_PROJECT_NAME "Set Library")
    set(DOXYGEN_PROJECT_NUMBER "1.0")
    set(DOXYGEN_PROJECT_BRIEF "Множество с поддержкой вложенных множеств")
    set(DOXYGEN_OUTPUT_LANGUAGE "Russian")
    set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C "YES")
    set(DOXYGEN_BUILTIN_STL_SUPPORT "YES")
    set(DOXYGEN_EXTRACT_LOCAL_CLASSES "YES")
    set(DOXYGEN_SOURCE_BROWSER "YES")
    set(DOXYGEN_INLINE_SOURCES "YES")
    set(DOXYGEN_REFERENCED_BY_RELATION "YES")
    set(DOXYGEN_REFERENCES_RELATION "YES")
    set(DOXYGEN_ALPHABETICAL_INDEX "YES")

    
    doxygen_add_docs(
            docs
            ${DOXYGEN_INPUT}
            COMMENT "Generating API documentation for Set library"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    
    add_custom_target(doc-open
            COMMAND echo "Documentation generated at: ${DOXYGEN_OUTPUT_DIRECTORY}/html/index.html"
            DEPENDS SetDocs
    )

    message(STATUS "Doxygen found: documentation target 'SetDocs' available")
else()
    message(WARNING "Doxygen not found! Documentation will not be generated.")
endif()

cmake_minimum_required(VERSION 3.18)
project(glit VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED GLIT_MASTER_PROJECT)
    if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        set(GLIT_MASTER_PROJECT ON)
    else()
        set(GLIT_MASTER_PROJECT OFF)
    endif()
endif()

option(GLIT_BUILD_DOCS "Build glit documentation with Doxygen" ${GLIT_MASTER_PROJECT})
option(GLIT_USE_INSTALLED_DEPS
    "Resolve glit's dependencies via user-installed packages; requires defining <package>_DIR"
    OFF
)

message(STATUS "glit - Configuring external dependencies")
add_subdirectory(external)
add_executable(${PROJECT_NAME} src/main.cpp)
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} PUBLIC glad_gl_core_33 glfw glm::glm imgui libgit2package spdlog::spdlog cxxopts::cxxopts)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_compile_definitions(${PROJECT_NAME} PRIVATE -DGLFW_INCLUDE_NONE -DIMGUI_DEFINE_MATH_OPERATORS)

if (GLIT_BUILD_DOCS)
    message(STATUS "glit - Configuring documentation")
    add_subdirectory(docs)
endif()

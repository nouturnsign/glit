set(BUILD_SHARED_LIBS OFF CACHE BOOL "")

# Project-specific Dependencies (not user-installed)

message(STATUS "glit - Using bundled dependencies for glad and Dear Imgui")

add_library(glad_gl_core_33 glad/src/gl.c)
target_include_directories(glad_gl_core_33 PUBLIC glad/include)

add_library(imgui
    imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC imgui imgui/backends glfw/include)

# User-Installable Dependencies (either use user-installed or bundled submodule)

if(GLIT_USE_INSTALLED_DEPS)
    message(STATUS "glit - Using user-installed dependencies for GLFW, GLM, libgit2, and spdlog")
    find_package(glfw3 3.4 REQUIRED)
    find_package(glm 1.0.1 REQUIRED)
    find_package(libgit2 1.8.1 REQUIRED)
    find_package(spdlog 1.14.1 REQUIRED)
else()
    message(STATUS "glit - Using bundled dependencies for GLFW, GLM, libgit2, and spdlog")

    set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
    set(GLFW_INSTALL OFF CACHE BOOL "")
    add_subdirectory(glfw)

    set(GLM_ENABLE_CXX_17 ON CACHE BOOL "")
    add_subdirectory(glm)

    set(BUILD_TESTS OFF CACHE BOOL "")
    set(BUILD_CLI OFF CACHE BOOL "")
    set(DEPRECATE_HARD ON CACHE BOOL "")
    add_subdirectory(libgit2)

    add_subdirectory(spdlog)
endif()

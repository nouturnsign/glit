set(BUILD_SHARED_LIBS OFF CACHE BOOL "")

add_library(glad_gl_core_33 glad/src/gl.c)
target_include_directories(glad_gl_core_33 PUBLIC glad/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")
add_subdirectory(glfw)

set(GLM_ENABLE_CXX_17 ON CACHE BOOL "")
add_subdirectory(glm)

add_library(imgui
    imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC imgui imgui/backends glfw/include)

set(BUILD_TESTS OFF CACHE BOOL "")
set(BUILD_CLI OFF CACHE BOOL "")
set(DEPRECATE_HARD ON CACHE BOOL "")
add_subdirectory(libgit2)

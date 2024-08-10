cmake_minimum_required(VERSION 3.18)
project(glit VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC glad_gl_core_33 glfw glm::glm imgui libgit2 util libgit2package)
target_include_directories(${PROJECT_NAME} PUBLIC include)

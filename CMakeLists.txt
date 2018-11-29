cmake_minimum_required(VERSION 3.12)
project(OpenBaseProject)

add_executable(OpenGLBaseProject)
set_target_properties(OpenGLBaseProject PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_sources(
        OpenGLBaseProject
        PUBLIC
        # Headers go here
        PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/src/Application.cpp"
)

target_compile_features(
        OpenGLBaseProject
        PUBLIC
        cxx_std_17
)

target_include_directories(
        OpenGLBaseProject
        PUBLIC
        include
)

add_subdirectory(libs/glew)
add_subdirectory(libs/glfw)

target_link_libraries(
        OpenGLBaseProject
        glew
        glfw
)

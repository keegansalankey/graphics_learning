# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Tutorials)

find_package(OpenGL REQUIRED)

# Compile external dependencies 
add_subdirectory (external)

include_directories(
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	.
  includes/
)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB INC_FILES ${PROJECT_SOURCE_DIR}/includes/*.h)
add_library(includes ${SRC_FILES} ${INC_FILES}) 

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
  includes
)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

add_executable(basics 
	basics/main.cpp
)

set_target_properties(basics PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/basics")

target_link_libraries(basics
	${ALL_LIBS}
)

add_executable(lighting
  lighting/lighting.cpp
)

set_target_properties(lighting PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lighting")

target_link_libraries(lighting
  ${ALL_LIBS}
)

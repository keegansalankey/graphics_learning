# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/keegan/graphics/my_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keegan/graphics/my_project

# Include any dependencies generated for this target.
include external/glfw-3.1.2/examples/CMakeFiles/boing.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/examples/CMakeFiles/boing.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/examples/CMakeFiles/boing.dir/flags.make

external/glfw-3.1.2/examples/CMakeFiles/boing.dir/boing.c.o: external/glfw-3.1.2/examples/CMakeFiles/boing.dir/flags.make
external/glfw-3.1.2/examples/CMakeFiles/boing.dir/boing.c.o: external/glfw-3.1.2/examples/boing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keegan/graphics/my_project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/examples/CMakeFiles/boing.dir/boing.c.o"
	cd /home/keegan/graphics/my_project/external/glfw-3.1.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/boing.dir/boing.c.o   -c /home/keegan/graphics/my_project/external/glfw-3.1.2/examples/boing.c

external/glfw-3.1.2/examples/CMakeFiles/boing.dir/boing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/boing.dir/boing.c.i"
	cd /home/keegan/graphics/my_project/external/glfw-3.1.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/keegan/graphics/my_project/external/glfw-3.1.2/examples/boing.c > CMakeFiles/boing.dir/boing.c.i

external/glfw-3.1.2/examples/CMakeFiles/boing.dir/boing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/boing.dir/boing.c.s"
	cd /home/keegan/graphics/my_project/external/glfw-3.1.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/keegan/graphics/my_project/external/glfw-3.1.2/examples/boing.c -o CMakeFiles/boing.dir/boing.c.s

# Object files for target boing
boing_OBJECTS = \
"CMakeFiles/boing.dir/boing.c.o"

# External object files for target boing
boing_EXTERNAL_OBJECTS =

external/glfw-3.1.2/examples/boing: external/glfw-3.1.2/examples/CMakeFiles/boing.dir/boing.c.o
external/glfw-3.1.2/examples/boing: external/glfw-3.1.2/examples/CMakeFiles/boing.dir/build.make
external/glfw-3.1.2/examples/boing: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/examples/boing: /usr/lib/x86_64-linux-gnu/librt.so
external/glfw-3.1.2/examples/boing: /usr/lib/x86_64-linux-gnu/libm.so
external/glfw-3.1.2/examples/boing: /usr/lib/x86_64-linux-gnu/libX11.so
external/glfw-3.1.2/examples/boing: /usr/lib/x86_64-linux-gnu/libXrandr.so
external/glfw-3.1.2/examples/boing: /usr/lib/x86_64-linux-gnu/libXinerama.so
external/glfw-3.1.2/examples/boing: /usr/lib/x86_64-linux-gnu/libXi.so
external/glfw-3.1.2/examples/boing: /usr/lib/x86_64-linux-gnu/libXcursor.so
external/glfw-3.1.2/examples/boing: /usr/lib/x86_64-linux-gnu/libGL.so
external/glfw-3.1.2/examples/boing: external/glfw-3.1.2/examples/CMakeFiles/boing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keegan/graphics/my_project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable boing"
	cd /home/keegan/graphics/my_project/external/glfw-3.1.2/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/examples/CMakeFiles/boing.dir/build: external/glfw-3.1.2/examples/boing

.PHONY : external/glfw-3.1.2/examples/CMakeFiles/boing.dir/build

external/glfw-3.1.2/examples/CMakeFiles/boing.dir/clean:
	cd /home/keegan/graphics/my_project/external/glfw-3.1.2/examples && $(CMAKE_COMMAND) -P CMakeFiles/boing.dir/cmake_clean.cmake
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/boing.dir/clean

external/glfw-3.1.2/examples/CMakeFiles/boing.dir/depend:
	cd /home/keegan/graphics/my_project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keegan/graphics/my_project /home/keegan/graphics/my_project/external/glfw-3.1.2/examples /home/keegan/graphics/my_project /home/keegan/graphics/my_project/external/glfw-3.1.2/examples /home/keegan/graphics/my_project/external/glfw-3.1.2/examples/CMakeFiles/boing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/examples/CMakeFiles/boing.dir/depend


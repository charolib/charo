# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tery/Projects/cpp/charo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tery/Projects/cpp/charo/build

# Include any dependencies generated for this target.
include examples/simple_project/CMakeFiles/simple_project_example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/simple_project/CMakeFiles/simple_project_example.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/simple_project/CMakeFiles/simple_project_example.dir/progress.make

# Include the compile flags for this target's objects.
include examples/simple_project/CMakeFiles/simple_project_example.dir/flags.make

examples/simple_project/CMakeFiles/simple_project_example.dir/main.cpp.o: examples/simple_project/CMakeFiles/simple_project_example.dir/flags.make
examples/simple_project/CMakeFiles/simple_project_example.dir/main.cpp.o: /home/tery/Projects/cpp/charo/examples/simple_project/main.cpp
examples/simple_project/CMakeFiles/simple_project_example.dir/main.cpp.o: examples/simple_project/CMakeFiles/simple_project_example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/simple_project/CMakeFiles/simple_project_example.dir/main.cpp.o"
	cd /home/tery/Projects/cpp/charo/build/examples/simple_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/simple_project/CMakeFiles/simple_project_example.dir/main.cpp.o -MF CMakeFiles/simple_project_example.dir/main.cpp.o.d -o CMakeFiles/simple_project_example.dir/main.cpp.o -c /home/tery/Projects/cpp/charo/examples/simple_project/main.cpp

examples/simple_project/CMakeFiles/simple_project_example.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/simple_project_example.dir/main.cpp.i"
	cd /home/tery/Projects/cpp/charo/build/examples/simple_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/examples/simple_project/main.cpp > CMakeFiles/simple_project_example.dir/main.cpp.i

examples/simple_project/CMakeFiles/simple_project_example.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/simple_project_example.dir/main.cpp.s"
	cd /home/tery/Projects/cpp/charo/build/examples/simple_project && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/examples/simple_project/main.cpp -o CMakeFiles/simple_project_example.dir/main.cpp.s

# Object files for target simple_project_example
simple_project_example_OBJECTS = \
"CMakeFiles/simple_project_example.dir/main.cpp.o"

# External object files for target simple_project_example
simple_project_example_EXTERNAL_OBJECTS =

bin/simple_project_example: examples/simple_project/CMakeFiles/simple_project_example.dir/main.cpp.o
bin/simple_project_example: examples/simple_project/CMakeFiles/simple_project_example.dir/build.make
bin/simple_project_example: libcharo.a
bin/simple_project_example: examples/simple_project/CMakeFiles/simple_project_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/simple_project_example"
	cd /home/tery/Projects/cpp/charo/build/examples/simple_project && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_project_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/simple_project/CMakeFiles/simple_project_example.dir/build: bin/simple_project_example
.PHONY : examples/simple_project/CMakeFiles/simple_project_example.dir/build

examples/simple_project/CMakeFiles/simple_project_example.dir/clean:
	cd /home/tery/Projects/cpp/charo/build/examples/simple_project && $(CMAKE_COMMAND) -P CMakeFiles/simple_project_example.dir/cmake_clean.cmake
.PHONY : examples/simple_project/CMakeFiles/simple_project_example.dir/clean

examples/simple_project/CMakeFiles/simple_project_example.dir/depend:
	cd /home/tery/Projects/cpp/charo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tery/Projects/cpp/charo /home/tery/Projects/cpp/charo/examples/simple_project /home/tery/Projects/cpp/charo/build /home/tery/Projects/cpp/charo/build/examples/simple_project /home/tery/Projects/cpp/charo/build/examples/simple_project/CMakeFiles/simple_project_example.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : examples/simple_project/CMakeFiles/simple_project_example.dir/depend


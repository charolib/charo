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
include CMakeFiles/charo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/charo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/charo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/charo.dir/flags.make

CMakeFiles/charo.dir/src/event/key.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/event/key.cpp.o: /home/tery/Projects/cpp/charo/src/event/key.cpp
CMakeFiles/charo.dir/src/event/key.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/charo.dir/src/event/key.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/event/key.cpp.o -MF CMakeFiles/charo.dir/src/event/key.cpp.o.d -o CMakeFiles/charo.dir/src/event/key.cpp.o -c /home/tery/Projects/cpp/charo/src/event/key.cpp

CMakeFiles/charo.dir/src/event/key.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/event/key.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/event/key.cpp > CMakeFiles/charo.dir/src/event/key.cpp.i

CMakeFiles/charo.dir/src/event/key.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/event/key.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/event/key.cpp -o CMakeFiles/charo.dir/src/event/key.cpp.s

CMakeFiles/charo.dir/src/event/events.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/event/events.cpp.o: /home/tery/Projects/cpp/charo/src/event/events.cpp
CMakeFiles/charo.dir/src/event/events.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/charo.dir/src/event/events.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/event/events.cpp.o -MF CMakeFiles/charo.dir/src/event/events.cpp.o.d -o CMakeFiles/charo.dir/src/event/events.cpp.o -c /home/tery/Projects/cpp/charo/src/event/events.cpp

CMakeFiles/charo.dir/src/event/events.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/event/events.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/event/events.cpp > CMakeFiles/charo.dir/src/event/events.cpp.i

CMakeFiles/charo.dir/src/event/events.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/event/events.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/event/events.cpp -o CMakeFiles/charo.dir/src/event/events.cpp.s

CMakeFiles/charo.dir/src/render/converter.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/converter.cpp.o: /home/tery/Projects/cpp/charo/src/render/converter.cpp
CMakeFiles/charo.dir/src/render/converter.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/charo.dir/src/render/converter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/converter.cpp.o -MF CMakeFiles/charo.dir/src/render/converter.cpp.o.d -o CMakeFiles/charo.dir/src/render/converter.cpp.o -c /home/tery/Projects/cpp/charo/src/render/converter.cpp

CMakeFiles/charo.dir/src/render/converter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/converter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/converter.cpp > CMakeFiles/charo.dir/src/render/converter.cpp.i

CMakeFiles/charo.dir/src/render/converter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/converter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/converter.cpp -o CMakeFiles/charo.dir/src/render/converter.cpp.s

CMakeFiles/charo.dir/src/render/glyphspace.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/glyphspace.cpp.o: /home/tery/Projects/cpp/charo/src/render/glyphspace.cpp
CMakeFiles/charo.dir/src/render/glyphspace.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/charo.dir/src/render/glyphspace.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/glyphspace.cpp.o -MF CMakeFiles/charo.dir/src/render/glyphspace.cpp.o.d -o CMakeFiles/charo.dir/src/render/glyphspace.cpp.o -c /home/tery/Projects/cpp/charo/src/render/glyphspace.cpp

CMakeFiles/charo.dir/src/render/glyphspace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/glyphspace.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/glyphspace.cpp > CMakeFiles/charo.dir/src/render/glyphspace.cpp.i

CMakeFiles/charo.dir/src/render/glyphspace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/glyphspace.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/glyphspace.cpp -o CMakeFiles/charo.dir/src/render/glyphspace.cpp.s

CMakeFiles/charo.dir/src/render/escape.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/escape.cpp.o: /home/tery/Projects/cpp/charo/src/render/escape.cpp
CMakeFiles/charo.dir/src/render/escape.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/charo.dir/src/render/escape.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/escape.cpp.o -MF CMakeFiles/charo.dir/src/render/escape.cpp.o.d -o CMakeFiles/charo.dir/src/render/escape.cpp.o -c /home/tery/Projects/cpp/charo/src/render/escape.cpp

CMakeFiles/charo.dir/src/render/escape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/escape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/escape.cpp > CMakeFiles/charo.dir/src/render/escape.cpp.i

CMakeFiles/charo.dir/src/render/escape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/escape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/escape.cpp -o CMakeFiles/charo.dir/src/render/escape.cpp.s

CMakeFiles/charo.dir/src/render/screen.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/screen.cpp.o: /home/tery/Projects/cpp/charo/src/render/screen.cpp
CMakeFiles/charo.dir/src/render/screen.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/charo.dir/src/render/screen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/screen.cpp.o -MF CMakeFiles/charo.dir/src/render/screen.cpp.o.d -o CMakeFiles/charo.dir/src/render/screen.cpp.o -c /home/tery/Projects/cpp/charo/src/render/screen.cpp

CMakeFiles/charo.dir/src/render/screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/screen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/screen.cpp > CMakeFiles/charo.dir/src/render/screen.cpp.i

CMakeFiles/charo.dir/src/render/screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/screen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/screen.cpp -o CMakeFiles/charo.dir/src/render/screen.cpp.s

CMakeFiles/charo.dir/src/render/widgets.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/widgets.cpp.o: /home/tery/Projects/cpp/charo/src/render/widgets.cpp
CMakeFiles/charo.dir/src/render/widgets.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/charo.dir/src/render/widgets.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/widgets.cpp.o -MF CMakeFiles/charo.dir/src/render/widgets.cpp.o.d -o CMakeFiles/charo.dir/src/render/widgets.cpp.o -c /home/tery/Projects/cpp/charo/src/render/widgets.cpp

CMakeFiles/charo.dir/src/render/widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/widgets.cpp > CMakeFiles/charo.dir/src/render/widgets.cpp.i

CMakeFiles/charo.dir/src/render/widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/widgets.cpp -o CMakeFiles/charo.dir/src/render/widgets.cpp.s

CMakeFiles/charo.dir/src/render/widgets/text.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/widgets/text.cpp.o: /home/tery/Projects/cpp/charo/src/render/widgets/text.cpp
CMakeFiles/charo.dir/src/render/widgets/text.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/charo.dir/src/render/widgets/text.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/widgets/text.cpp.o -MF CMakeFiles/charo.dir/src/render/widgets/text.cpp.o.d -o CMakeFiles/charo.dir/src/render/widgets/text.cpp.o -c /home/tery/Projects/cpp/charo/src/render/widgets/text.cpp

CMakeFiles/charo.dir/src/render/widgets/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/widgets/text.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/widgets/text.cpp > CMakeFiles/charo.dir/src/render/widgets/text.cpp.i

CMakeFiles/charo.dir/src/render/widgets/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/widgets/text.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/widgets/text.cpp -o CMakeFiles/charo.dir/src/render/widgets/text.cpp.s

CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o: /home/tery/Projects/cpp/charo/src/render/widgets/text_styled.cpp
CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o -MF CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o.d -o CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o -c /home/tery/Projects/cpp/charo/src/render/widgets/text_styled.cpp

CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/widgets/text_styled.cpp > CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.i

CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/widgets/text_styled.cpp -o CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.s

CMakeFiles/charo.dir/src/render/widgets/button.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/widgets/button.cpp.o: /home/tery/Projects/cpp/charo/src/render/widgets/button.cpp
CMakeFiles/charo.dir/src/render/widgets/button.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/charo.dir/src/render/widgets/button.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/widgets/button.cpp.o -MF CMakeFiles/charo.dir/src/render/widgets/button.cpp.o.d -o CMakeFiles/charo.dir/src/render/widgets/button.cpp.o -c /home/tery/Projects/cpp/charo/src/render/widgets/button.cpp

CMakeFiles/charo.dir/src/render/widgets/button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/widgets/button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/widgets/button.cpp > CMakeFiles/charo.dir/src/render/widgets/button.cpp.i

CMakeFiles/charo.dir/src/render/widgets/button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/widgets/button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/widgets/button.cpp -o CMakeFiles/charo.dir/src/render/widgets/button.cpp.s

CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o: /home/tery/Projects/cpp/charo/src/render/widgets/checkbox.cpp
CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o -MF CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o.d -o CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o -c /home/tery/Projects/cpp/charo/src/render/widgets/checkbox.cpp

CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/render/widgets/checkbox.cpp > CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.i

CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/render/widgets/checkbox.cpp -o CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.s

CMakeFiles/charo.dir/src/terminal.cpp.o: CMakeFiles/charo.dir/flags.make
CMakeFiles/charo.dir/src/terminal.cpp.o: /home/tery/Projects/cpp/charo/src/terminal.cpp
CMakeFiles/charo.dir/src/terminal.cpp.o: CMakeFiles/charo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/charo.dir/src/terminal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/charo.dir/src/terminal.cpp.o -MF CMakeFiles/charo.dir/src/terminal.cpp.o.d -o CMakeFiles/charo.dir/src/terminal.cpp.o -c /home/tery/Projects/cpp/charo/src/terminal.cpp

CMakeFiles/charo.dir/src/terminal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/charo.dir/src/terminal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tery/Projects/cpp/charo/src/terminal.cpp > CMakeFiles/charo.dir/src/terminal.cpp.i

CMakeFiles/charo.dir/src/terminal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/charo.dir/src/terminal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tery/Projects/cpp/charo/src/terminal.cpp -o CMakeFiles/charo.dir/src/terminal.cpp.s

# Object files for target charo
charo_OBJECTS = \
"CMakeFiles/charo.dir/src/event/key.cpp.o" \
"CMakeFiles/charo.dir/src/event/events.cpp.o" \
"CMakeFiles/charo.dir/src/render/converter.cpp.o" \
"CMakeFiles/charo.dir/src/render/glyphspace.cpp.o" \
"CMakeFiles/charo.dir/src/render/escape.cpp.o" \
"CMakeFiles/charo.dir/src/render/screen.cpp.o" \
"CMakeFiles/charo.dir/src/render/widgets.cpp.o" \
"CMakeFiles/charo.dir/src/render/widgets/text.cpp.o" \
"CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o" \
"CMakeFiles/charo.dir/src/render/widgets/button.cpp.o" \
"CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o" \
"CMakeFiles/charo.dir/src/terminal.cpp.o"

# External object files for target charo
charo_EXTERNAL_OBJECTS =

libcharo.a: CMakeFiles/charo.dir/src/event/key.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/event/events.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/converter.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/glyphspace.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/escape.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/screen.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/widgets.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/widgets/text.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/widgets/text_styled.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/widgets/button.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/render/widgets/checkbox.cpp.o
libcharo.a: CMakeFiles/charo.dir/src/terminal.cpp.o
libcharo.a: CMakeFiles/charo.dir/build.make
libcharo.a: CMakeFiles/charo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tery/Projects/cpp/charo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX static library libcharo.a"
	$(CMAKE_COMMAND) -P CMakeFiles/charo.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/charo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/charo.dir/build: libcharo.a
.PHONY : CMakeFiles/charo.dir/build

CMakeFiles/charo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/charo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/charo.dir/clean

CMakeFiles/charo.dir/depend:
	cd /home/tery/Projects/cpp/charo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tery/Projects/cpp/charo /home/tery/Projects/cpp/charo /home/tery/Projects/cpp/charo/build /home/tery/Projects/cpp/charo/build /home/tery/Projects/cpp/charo/build/CMakeFiles/charo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/charo.dir/depend


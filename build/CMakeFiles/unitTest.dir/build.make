# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/tforys/proi_projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tforys/proi_projekt/build

# Include any dependencies generated for this target.
include CMakeFiles/unitTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/unitTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/unitTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unitTest.dir/flags.make

CMakeFiles/unitTest.dir/UnitTest.cpp.o: CMakeFiles/unitTest.dir/flags.make
CMakeFiles/unitTest.dir/UnitTest.cpp.o: ../UnitTest.cpp
CMakeFiles/unitTest.dir/UnitTest.cpp.o: CMakeFiles/unitTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tforys/proi_projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unitTest.dir/UnitTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/unitTest.dir/UnitTest.cpp.o -MF CMakeFiles/unitTest.dir/UnitTest.cpp.o.d -o CMakeFiles/unitTest.dir/UnitTest.cpp.o -c /home/tforys/proi_projekt/UnitTest.cpp

CMakeFiles/unitTest.dir/UnitTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unitTest.dir/UnitTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tforys/proi_projekt/UnitTest.cpp > CMakeFiles/unitTest.dir/UnitTest.cpp.i

CMakeFiles/unitTest.dir/UnitTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unitTest.dir/UnitTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tforys/proi_projekt/UnitTest.cpp -o CMakeFiles/unitTest.dir/UnitTest.cpp.s

# Object files for target unitTest
unitTest_OBJECTS = \
"CMakeFiles/unitTest.dir/UnitTest.cpp.o"

# External object files for target unitTest
unitTest_EXTERNAL_OBJECTS =

unitTest: CMakeFiles/unitTest.dir/UnitTest.cpp.o
unitTest: CMakeFiles/unitTest.dir/build.make
unitTest: /usr/local/lib/libgtest.a
unitTest: CMakeFiles/unitTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tforys/proi_projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unitTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unitTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unitTest.dir/build: unitTest
.PHONY : CMakeFiles/unitTest.dir/build

CMakeFiles/unitTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unitTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unitTest.dir/clean

CMakeFiles/unitTest.dir/depend:
	cd /home/tforys/proi_projekt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tforys/proi_projekt /home/tforys/proi_projekt /home/tforys/proi_projekt/build /home/tforys/proi_projekt/build /home/tforys/proi_projekt/build/CMakeFiles/unitTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unitTest.dir/depend


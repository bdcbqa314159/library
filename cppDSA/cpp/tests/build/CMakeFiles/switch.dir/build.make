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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bernardocohen/repos/library/cppDSA/cpp/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build

# Include any dependencies generated for this target.
include CMakeFiles/switch.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/switch.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/switch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/switch.dir/flags.make

CMakeFiles/switch.dir/src/switch.cpp.o: CMakeFiles/switch.dir/flags.make
CMakeFiles/switch.dir/src/switch.cpp.o: ../src/switch.cpp
CMakeFiles/switch.dir/src/switch.cpp.o: CMakeFiles/switch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/library/cppDSA/cpp/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/switch.dir/src/switch.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/switch.dir/src/switch.cpp.o -MF CMakeFiles/switch.dir/src/switch.cpp.o.d -o CMakeFiles/switch.dir/src/switch.cpp.o -c /Users/bernardocohen/repos/library/cppDSA/cpp/tests/src/switch.cpp

CMakeFiles/switch.dir/src/switch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/switch.dir/src/switch.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/library/cppDSA/cpp/tests/src/switch.cpp > CMakeFiles/switch.dir/src/switch.cpp.i

CMakeFiles/switch.dir/src/switch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/switch.dir/src/switch.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/library/cppDSA/cpp/tests/src/switch.cpp -o CMakeFiles/switch.dir/src/switch.cpp.s

# Object files for target switch
switch_OBJECTS = \
"CMakeFiles/switch.dir/src/switch.cpp.o"

# External object files for target switch
switch_EXTERNAL_OBJECTS =

../bin/switch: CMakeFiles/switch.dir/src/switch.cpp.o
../bin/switch: CMakeFiles/switch.dir/build.make
../bin/switch: CMakeFiles/switch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bernardocohen/repos/library/cppDSA/cpp/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/switch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/switch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/switch.dir/build: ../bin/switch
.PHONY : CMakeFiles/switch.dir/build

CMakeFiles/switch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/switch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/switch.dir/clean

CMakeFiles/switch.dir/depend:
	cd /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bernardocohen/repos/library/cppDSA/cpp/tests /Users/bernardocohen/repos/library/cppDSA/cpp/tests /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build/CMakeFiles/switch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/switch.dir/depend


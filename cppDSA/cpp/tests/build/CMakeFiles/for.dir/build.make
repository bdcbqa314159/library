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
include CMakeFiles/for.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/for.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/for.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/for.dir/flags.make

CMakeFiles/for.dir/src/for.cpp.o: CMakeFiles/for.dir/flags.make
CMakeFiles/for.dir/src/for.cpp.o: ../src/for.cpp
CMakeFiles/for.dir/src/for.cpp.o: CMakeFiles/for.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/library/cppDSA/cpp/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/for.dir/src/for.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/for.dir/src/for.cpp.o -MF CMakeFiles/for.dir/src/for.cpp.o.d -o CMakeFiles/for.dir/src/for.cpp.o -c /Users/bernardocohen/repos/library/cppDSA/cpp/tests/src/for.cpp

CMakeFiles/for.dir/src/for.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/for.dir/src/for.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/library/cppDSA/cpp/tests/src/for.cpp > CMakeFiles/for.dir/src/for.cpp.i

CMakeFiles/for.dir/src/for.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/for.dir/src/for.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/library/cppDSA/cpp/tests/src/for.cpp -o CMakeFiles/for.dir/src/for.cpp.s

# Object files for target for
for_OBJECTS = \
"CMakeFiles/for.dir/src/for.cpp.o"

# External object files for target for
for_EXTERNAL_OBJECTS =

../bin/for: CMakeFiles/for.dir/src/for.cpp.o
../bin/for: CMakeFiles/for.dir/build.make
../bin/for: /usr/local/lib/libcppDSA.dylib
../bin/for: CMakeFiles/for.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bernardocohen/repos/library/cppDSA/cpp/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/for"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/for.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/for.dir/build: ../bin/for
.PHONY : CMakeFiles/for.dir/build

CMakeFiles/for.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/for.dir/cmake_clean.cmake
.PHONY : CMakeFiles/for.dir/clean

CMakeFiles/for.dir/depend:
	cd /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bernardocohen/repos/library/cppDSA/cpp/tests /Users/bernardocohen/repos/library/cppDSA/cpp/tests /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build /Users/bernardocohen/repos/library/cppDSA/cpp/tests/build/CMakeFiles/for.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/for.dir/depend

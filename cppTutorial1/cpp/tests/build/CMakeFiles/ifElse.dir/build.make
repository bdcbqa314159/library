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
CMAKE_SOURCE_DIR = /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/build

# Include any dependencies generated for this target.
include CMakeFiles/ifElse.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ifElse.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ifElse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ifElse.dir/flags.make

CMakeFiles/ifElse.dir/src/ifElse.cpp.o: CMakeFiles/ifElse.dir/flags.make
CMakeFiles/ifElse.dir/src/ifElse.cpp.o: ../src/ifElse.cpp
CMakeFiles/ifElse.dir/src/ifElse.cpp.o: CMakeFiles/ifElse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ifElse.dir/src/ifElse.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ifElse.dir/src/ifElse.cpp.o -MF CMakeFiles/ifElse.dir/src/ifElse.cpp.o.d -o CMakeFiles/ifElse.dir/src/ifElse.cpp.o -c /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/src/ifElse.cpp

CMakeFiles/ifElse.dir/src/ifElse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ifElse.dir/src/ifElse.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/src/ifElse.cpp > CMakeFiles/ifElse.dir/src/ifElse.cpp.i

CMakeFiles/ifElse.dir/src/ifElse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ifElse.dir/src/ifElse.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/src/ifElse.cpp -o CMakeFiles/ifElse.dir/src/ifElse.cpp.s

# Object files for target ifElse
ifElse_OBJECTS = \
"CMakeFiles/ifElse.dir/src/ifElse.cpp.o"

# External object files for target ifElse
ifElse_EXTERNAL_OBJECTS =

../bin/ifElse: CMakeFiles/ifElse.dir/src/ifElse.cpp.o
../bin/ifElse: CMakeFiles/ifElse.dir/build.make
../bin/ifElse: CMakeFiles/ifElse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/ifElse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ifElse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ifElse.dir/build: ../bin/ifElse
.PHONY : CMakeFiles/ifElse.dir/build

CMakeFiles/ifElse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ifElse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ifElse.dir/clean

CMakeFiles/ifElse.dir/depend:
	cd /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/build /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/build /Users/bernardocohen/repos/library/cppTutorial1/cpp/tests/build/CMakeFiles/ifElse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ifElse.dir/depend


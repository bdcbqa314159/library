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
CMAKE_SOURCE_DIR = /Users/bernardocohen/repos/library/cppBook4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bernardocohen/repos/library/cppBook4/build

# Include any dependencies generated for this target.
include CMakeFiles/myNumpy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myNumpy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myNumpy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myNumpy.dir/flags.make

CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o: CMakeFiles/myNumpy.dir/flags.make
CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o: ../cpp/src/interp_1d.cpp
CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o: CMakeFiles/myNumpy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/library/cppBook4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o -MF CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o.d -o CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o -c /Users/bernardocohen/repos/library/cppBook4/cpp/src/interp_1d.cpp

CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/library/cppBook4/cpp/src/interp_1d.cpp > CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.i

CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/library/cppBook4/cpp/src/interp_1d.cpp -o CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.s

CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o: CMakeFiles/myNumpy.dir/flags.make
CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o: ../cpp/src/interp_linear.cpp
CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o: CMakeFiles/myNumpy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/library/cppBook4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o -MF CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o.d -o CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o -c /Users/bernardocohen/repos/library/cppBook4/cpp/src/interp_linear.cpp

CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/library/cppBook4/cpp/src/interp_linear.cpp > CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.i

CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/library/cppBook4/cpp/src/interp_linear.cpp -o CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.s

CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o: CMakeFiles/myNumpy.dir/flags.make
CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o: ../cpp/src/test.cpp
CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o: CMakeFiles/myNumpy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/library/cppBook4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o -MF CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o.d -o CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o -c /Users/bernardocohen/repos/library/cppBook4/cpp/src/test.cpp

CMakeFiles/myNumpy.dir/cpp/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myNumpy.dir/cpp/src/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/library/cppBook4/cpp/src/test.cpp > CMakeFiles/myNumpy.dir/cpp/src/test.cpp.i

CMakeFiles/myNumpy.dir/cpp/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myNumpy.dir/cpp/src/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/library/cppBook4/cpp/src/test.cpp -o CMakeFiles/myNumpy.dir/cpp/src/test.cpp.s

CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o: CMakeFiles/myNumpy.dir/flags.make
CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o: ../python/cppBook4.cpp
CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o: CMakeFiles/myNumpy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/library/cppBook4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o -MF CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o.d -o CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o -c /Users/bernardocohen/repos/library/cppBook4/python/cppBook4.cpp

CMakeFiles/myNumpy.dir/python/cppBook4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myNumpy.dir/python/cppBook4.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/library/cppBook4/python/cppBook4.cpp > CMakeFiles/myNumpy.dir/python/cppBook4.cpp.i

CMakeFiles/myNumpy.dir/python/cppBook4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myNumpy.dir/python/cppBook4.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/library/cppBook4/python/cppBook4.cpp -o CMakeFiles/myNumpy.dir/python/cppBook4.cpp.s

CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o: CMakeFiles/myNumpy.dir/flags.make
CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o: ../python/myNumpy.cpp
CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o: CMakeFiles/myNumpy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bernardocohen/repos/library/cppBook4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o -MF CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o.d -o CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o -c /Users/bernardocohen/repos/library/cppBook4/python/myNumpy.cpp

CMakeFiles/myNumpy.dir/python/myNumpy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myNumpy.dir/python/myNumpy.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bernardocohen/repos/library/cppBook4/python/myNumpy.cpp > CMakeFiles/myNumpy.dir/python/myNumpy.cpp.i

CMakeFiles/myNumpy.dir/python/myNumpy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myNumpy.dir/python/myNumpy.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bernardocohen/repos/library/cppBook4/python/myNumpy.cpp -o CMakeFiles/myNumpy.dir/python/myNumpy.cpp.s

# Object files for target myNumpy
myNumpy_OBJECTS = \
"CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o" \
"CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o" \
"CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o" \
"CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o" \
"CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o"

# External object files for target myNumpy
myNumpy_EXTERNAL_OBJECTS =

myNumpy.cpython-39-darwin.so: CMakeFiles/myNumpy.dir/cpp/src/interp_1d.cpp.o
myNumpy.cpython-39-darwin.so: CMakeFiles/myNumpy.dir/cpp/src/interp_linear.cpp.o
myNumpy.cpython-39-darwin.so: CMakeFiles/myNumpy.dir/cpp/src/test.cpp.o
myNumpy.cpython-39-darwin.so: CMakeFiles/myNumpy.dir/python/cppBook4.cpp.o
myNumpy.cpython-39-darwin.so: CMakeFiles/myNumpy.dir/python/myNumpy.cpp.o
myNumpy.cpython-39-darwin.so: CMakeFiles/myNumpy.dir/build.make
myNumpy.cpython-39-darwin.so: CMakeFiles/myNumpy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bernardocohen/repos/library/cppBook4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared module myNumpy.cpython-39-darwin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myNumpy.dir/link.txt --verbose=$(VERBOSE)
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip -x /Users/bernardocohen/repos/library/cppBook4/build/myNumpy.cpython-39-darwin.so

# Rule to build all files generated by this target.
CMakeFiles/myNumpy.dir/build: myNumpy.cpython-39-darwin.so
.PHONY : CMakeFiles/myNumpy.dir/build

CMakeFiles/myNumpy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myNumpy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myNumpy.dir/clean

CMakeFiles/myNumpy.dir/depend:
	cd /Users/bernardocohen/repos/library/cppBook4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bernardocohen/repos/library/cppBook4 /Users/bernardocohen/repos/library/cppBook4 /Users/bernardocohen/repos/library/cppBook4/build /Users/bernardocohen/repos/library/cppBook4/build /Users/bernardocohen/repos/library/cppBook4/build/CMakeFiles/myNumpy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myNumpy.dir/depend


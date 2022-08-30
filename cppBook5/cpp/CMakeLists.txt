cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cppBook5 VERSION 0.1.0) # update here

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/cppBook5_bits") # update here

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/test.hpp
    ${PROJECT_INCLUDE_DIR}/book.hpp
    ${PROJECT_INCLUDE_DIR}/complex.hpp
    ${PROJECT_INCLUDE_DIR}/guest.hpp
    ${PROJECT_INCLUDE_DIR}/odeSolvers.hpp
    ${PROJECT_INCLUDE_DIR}/myException.hpp
    ${PROJECT_INCLUDE_DIR}/myVector.hpp

    ${PROJECT_SOURCE_DIR}/test.cpp
    ${PROJECT_SOURCE_DIR}/book.cpp
    ${PROJECT_SOURCE_DIR}/complex.cpp
    ${PROJECT_SOURCE_DIR}/guest.cpp
    ${PROJECT_SOURCE_DIR}/odeSolvers.cpp
    ${PROJECT_SOURCE_DIR}/myException.cpp
    ${PROJECT_SOURCE_DIR}/myVector.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(cppBook5 SHARED ${SOURCE_FILES}) # update here

# Include directories
target_include_directories(cppBook5 PRIVATE include/cppBook5_bits) # update here 2 times

# Install
install(TARGETS cppBook5 DESTINATION lib) # update here

# Install the headers
install(FILES include/cppBook5 DESTINATION include) # update here

# Create base directory
install(DIRECTORY include/cppBook5_bits DESTINATION include) # update here

cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cppTutorial3 VERSION 0.1.0) # update here

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/cppTutorial3_bits") # update here

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/test.hpp
    ${PROJECT_INCLUDE_DIR}/testing.hpp
    ${PROJECT_INCLUDE_DIR}/arrays.hpp
    ${PROJECT_INCLUDE_DIR}/sorting.hpp

    ${PROJECT_SOURCE_DIR}/test.cpp
    ${PROJECT_SOURCE_DIR}/testing.cpp
    ${PROJECT_SOURCE_DIR}/arrays.cpp
    ${PROJECT_SOURCE_DIR}/sorting.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(cppTutorial3 SHARED ${SOURCE_FILES}) # update here

# Include directories
target_include_directories(cppTutorial3 PRIVATE include/cppTutorial3_bits) # update here 2 times

# Install
install(TARGETS cppTutorial3 DESTINATION lib) # update here

# Install the headers
install(FILES include/cppTutorial3 DESTINATION include) # update here

# Create base directory
install(DIRECTORY include/cppTutorial3_bits DESTINATION include) # update here

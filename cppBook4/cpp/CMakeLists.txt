cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cppBook4 VERSION 0.1.0) # update here

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/cppBook4_bits") # update here

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/test.hpp
    ${PROJECT_INCLUDE_DIR}/nr.hpp
    ${PROJECT_INCLUDE_DIR}/interp_1d.hpp
    ${PROJECT_INCLUDE_DIR}/interp_linear.hpp
    ${PROJECT_INCLUDE_DIR}/polcoef.hpp
    ${PROJECT_INCLUDE_DIR}/interp_2d.hpp

    ${PROJECT_SOURCE_DIR}/test.cpp
    ${PROJECT_SOURCE_DIR}/interp_1d.cpp
    ${PROJECT_SOURCE_DIR}/interp_linear.cpp
    ${PROJECT_SOURCE_DIR}/polcoef.cpp
    ${PROJECT_SOURCE_DIR}/interp_2d.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(cppBook4 SHARED ${SOURCE_FILES}) # update here

# Include directories
target_include_directories(cppBook4 PRIVATE include/cppBook4_bits) # update here

# Install
install(TARGETS cppBook4 DESTINATION lib) # update here

# Install the headers
install(FILES include/cppBook4 DESTINATION include) # update here

# Create base directory
install(DIRECTORY include/cppBook4_bits DESTINATION include) # update here

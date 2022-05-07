cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cppTutorial2 VERSION 0.1.0) #update here

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/cppTutorial2_bits") #update here

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/test.hpp
    ${PROJECT_INCLUDE_DIR}/recursion.hpp
    ${PROJECT_INCLUDE_DIR}/search.hpp
    ${PROJECT_INCLUDE_DIR}/backtracking.hpp
    ${PROJECT_INCLUDE_DIR}/dynamicProg.hpp
    ${PROJECT_INCLUDE_DIR}/list.hpp
    ${PROJECT_INCLUDE_DIR}/linkedList.hpp
    ${PROJECT_INCLUDE_DIR}/stackArray.hpp
    ${PROJECT_INCLUDE_DIR}/stackLinkedList.hpp
    ${PROJECT_INCLUDE_DIR}/queue.hpp
    ${PROJECT_INCLUDE_DIR}/tree.hpp
    ${PROJECT_INCLUDE_DIR}/bst.hpp
    ${PROJECT_INCLUDE_DIR}/person.hpp
    ${PROJECT_INCLUDE_DIR}/heap.hpp
    
    ${PROJECT_SOURCE_DIR}/test.cpp
    ${PROJECT_SOURCE_DIR}/recursion.cpp
    ${PROJECT_SOURCE_DIR}/search.cpp
    ${PROJECT_SOURCE_DIR}/backtracking.cpp
    ${PROJECT_SOURCE_DIR}/dynamicProg.cpp
    ${PROJECT_SOURCE_DIR}/person.cpp
    ${PROJECT_SOURCE_DIR}/heap.cpp
    
    
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(cppTutorial2 SHARED ${SOURCE_FILES}) #update here

# Include directories
target_include_directories(cppTutorial2 PRIVATE include/cppTutorial2_bits) #update here

# Install
install(TARGETS cppTutorial2 DESTINATION lib) #update here

# Install the headers
install(FILES include/cppTutorial2 DESTINATION include) #update here

# Create base directory
install(DIRECTORY include/cppTutorial2_bits DESTINATION include) #update here

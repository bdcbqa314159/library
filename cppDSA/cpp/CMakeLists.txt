cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cppDSA VERSION 0.1.0)

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/cppDSA_bits")

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/test.hpp
    ${PROJECT_INCLUDE_DIR}/random.hpp
    ${PROJECT_INCLUDE_DIR}/cards.hpp
    ${PROJECT_INCLUDE_DIR}/animal.hpp
    ${PROJECT_INCLUDE_DIR}/list.hpp
    ${PROJECT_INCLUDE_DIR}/node.hpp
    ${PROJECT_INCLUDE_DIR}/linkedList.hpp
    ${PROJECT_INCLUDE_DIR}/doublyLinkedList.hpp
    ${PROJECT_INCLUDE_DIR}/stack.hpp
    ${PROJECT_INCLUDE_DIR}/queue.hpp
    ${PROJECT_INCLUDE_DIR}/deque.hpp
    ${PROJECT_INCLUDE_DIR}/sorting.hpp
    ${PROJECT_INCLUDE_DIR}/searching.hpp
    ${PROJECT_INCLUDE_DIR}/strings.hpp
    ${PROJECT_INCLUDE_DIR}/treeNode.hpp
    ${PROJECT_INCLUDE_DIR}/trees.hpp
    ${PROJECT_INCLUDE_DIR}/hashTables.hpp
    ${PROJECT_INCLUDE_DIR}/realLifeAlgorithms.hpp
    ${PROJECT_INCLUDE_DIR}/minHeapNode.hpp
    
    ${PROJECT_SOURCE_DIR}/test.cpp
    ${PROJECT_SOURCE_DIR}/random.cpp
    ${PROJECT_SOURCE_DIR}/cards.cpp
    ${PROJECT_SOURCE_DIR}/list.cpp
    ${PROJECT_SOURCE_DIR}/sorting.cpp
    ${PROJECT_SOURCE_DIR}/searching.cpp
    ${PROJECT_SOURCE_DIR}/strings.cpp
    ${PROJECT_SOURCE_DIR}/treeNode.cpp
    ${PROJECT_SOURCE_DIR}/trees.cpp
    ${PROJECT_SOURCE_DIR}/hashTables.cpp
    ${PROJECT_SOURCE_DIR}/realLifeAlgorithms.cpp
    ${PROJECT_SOURCE_DIR}/minHeapNode.cpp
    
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(cppDSA SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(cppDSA PRIVATE include/cppDSA_bits)

# Install
install(TARGETS cppDSA DESTINATION lib)

# Install the headers
install(FILES include/cppDSA DESTINATION include)

# Create base directory
install(DIRECTORY include/cppDSA_bits DESTINATION include)

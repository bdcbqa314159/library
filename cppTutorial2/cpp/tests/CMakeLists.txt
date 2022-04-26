cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(CPPTUTORIAL2_LIB cppTutorial2 HINTS /usr/local/lib/) #update here

add_executable(test src/test.cpp)
add_executable(recursion src/recursion.cpp)
add_executable(search src/search.cpp)

add_executable(backtracking src/backtracking.cpp)

target_link_libraries(test PUBLIC ${CPPTUTORIAL2_LIB}) #update here
target_link_libraries(recursion PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(search PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(backtracking PUBLIC ${CPPTUTORIAL2_LIB})

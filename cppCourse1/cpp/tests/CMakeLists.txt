cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(CPPCOURSE1_LIB cppCourse1 HINTS /usr/local/lib/) # update here

add_executable(test src/test.cpp)

target_link_libraries(test PUBLIC ${CPPCOURSE1_LIB}) # update here

add_executable(lecture1 src/lecture1.cpp)

target_link_libraries(lecture1 PUBLIC ${CPPCOURSE1_LIB}) # update here

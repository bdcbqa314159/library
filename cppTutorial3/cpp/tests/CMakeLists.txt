cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(CPPTUTORIAL3_LIB cppTutorial3 HINTS /usr/local/lib/) # update here

add_executable(test src/test.cpp)

target_link_libraries(test PUBLIC ${CPPTUTORIAL3_LIB}) # update here

add_executable(arrays src/arrays.cpp)

target_link_libraries(arrays PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(sorting src/sorting.cpp)

target_link_libraries(sorting PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(strings src/strings.cpp)

target_link_libraries(strings PUBLIC ${CPPTUTORIAL3_LIB})
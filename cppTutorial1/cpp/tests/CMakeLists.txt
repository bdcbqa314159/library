cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(CPPTUTORIAL1_LIB cppTutorial1 HINTS /usr/local/lib/) #update here

add_executable(test src/test.cpp)
add_executable(helloWorld src/helloWorld.cpp)
add_executable(outPut src/outPuttingText.cpp)
add_executable(variables src/variables.cpp)
add_executable(strings src/strings.cpp)
add_executable(input src/input.cpp)
add_executable(integerType src/integerType.cpp)
add_executable(floatingType src/floatingType.cpp)
add_executable(charBool src/charBool.cpp)
add_executable(if src/if.cpp)
add_executable(ifElse src/ifElse.cpp)
add_executable(ifElseIfElse src/ifElseIfElse.cpp)
add_executable(comparingFloats src/comparingFloats.cpp)

target_link_libraries(test PUBLIC ${CPPTUTORIAL1_LIB}) #update here


cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)
find_package(SDL2 REQUIRED)

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
add_executable(cppConditions src/cppConditions.cpp)
add_executable(while src/while.cpp)
add_executable(doWhile src/doWhile.cpp)
add_executable(for src/for.cpp)
add_executable(breakContinue src/breakContinue.cpp)
add_executable(arrays src/arrays.cpp)
add_executable(multiDimArrays src/multiDimArrays.cpp)
add_executable(sizeofArrays src/sizeofArrays.cpp)
add_executable(sizeofMultiDimArrays src/sizeofMultiDimArrays.cpp)
add_executable(switch src/switch.cpp)

add_executable(functions src/functions.cpp)
add_executable(returnValue src/returnValue.cpp)
add_executable(functionsParams src/functionsParams.cpp)
add_executable(headersInclude src/headersInclude.cpp)

add_executable(classes src/classes.cpp)
add_executable(stringStreams src/stringStreams.cpp)

add_executable(pointers src/pointers.cpp)
add_executable(arithmetic src/arithmetic.cpp)
add_executable(references src/references.cpp)

add_executable(const src/const.cpp)

add_executable(namespaces src/namespaces.cpp)

add_executable(inheritance src/inheritance.cpp)

add_executable(complements src/complements.cpp)

add_executable(testingSDL src/testingSDL.cpp)
add_executable(particle src/particle.cpp)

add_executable(bitsShift src/bitsShift.cpp)
add_executable(bitWise src/bitWise.cpp)
add_executable(bonus src/bonus.cpp)

target_link_libraries(test PUBLIC ${CPPTUTORIAL1_LIB}) #update here

target_link_libraries(headersInclude PUBLIC ${CPPTUTORIAL1_LIB})

target_link_libraries(classes PUBLIC ${CPPTUTORIAL1_LIB})

target_link_libraries(namespaces PUBLIC ${CPPTUTORIAL1_LIB})

target_link_libraries(testingSDL PUBLIC ${CPPTUTORIAL1_LIB})
target_link_libraries(testingSDL PUBLIC ${SDL2_LIBRARIES})

target_link_libraries(particle PUBLIC ${CPPTUTORIAL1_LIB})
target_link_libraries(particle PUBLIC ${SDL2_LIBRARIES})
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(CPPTUTORIAL4_LIB cppTutorial4 HINTS /usr/local/lib/) # update here

add_executable(test src/test.cpp)

target_link_libraries(test PUBLIC ${CPPTUTORIAL4_LIB}) # update here

add_executable(introduction src/introduction.cpp)

target_link_libraries(introduction PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(conditions src/conditions.cpp)

target_link_libraries(conditions PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(loops src/loops.cpp)

target_link_libraries(loops PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(arrays src/arrays.cpp)

target_link_libraries(arrays PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(pointers src/pointers.cpp)

target_link_libraries(pointers PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(strings src/strings.cpp)

target_link_libraries(strings PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(functions src/functions.cpp)

target_link_libraries(functions PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(oops src/oops.cpp)

target_link_libraries(oops PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(overloading src/overloading.cpp)

target_link_libraries(overloading PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(inheritance src/inheritance.cpp)

target_link_libraries(inheritance PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(baseClassPointer src/baseClassPointer.cpp)

target_link_libraries(baseClassPointer PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(polymorphism src/polymorphism.cpp)

target_link_libraries(polymorphism PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(errors src/errors.cpp)

target_link_libraries(errors PUBLIC ${CPPTUTORIAL4_LIB})

add_executable(ios src/ios.cpp)

target_link_libraries(ios PUBLIC ${CPPTUTORIAL4_LIB})
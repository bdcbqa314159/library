cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(CPPDSA_LIB cppDSA HINTS /usr/local/lib/)

add_executable(test src/test.cpp)
add_executable(in_out src/in_out.cpp)
add_executable(hello src/hello.cpp)
add_executable(ifElse src/ifElse.cpp)
add_executable(ifElseIf src/ifElseIf.cpp)
add_executable(ifElseIf2 src/ifElseIf2.cpp)
add_executable(switch src/switch.cpp)
add_executable(for src/for.cpp)
add_executable(while src/while.cpp)
add_executable(doWhile src/doWhile.cpp)
add_executable(cards src/cards.cpp)
add_executable(animal src/animal.cpp)
add_executable(template src/template.cpp)
add_executable(classTemplate src/classTemplate.cpp)

target_link_libraries(test PUBLIC ${CPPDSA_LIB})
target_link_libraries(for PUBLIC ${CPPDSA_LIB})
target_link_libraries(while PUBLIC ${CPPDSA_LIB})
target_link_libraries(doWhile PUBLIC ${CPPDSA_LIB})
target_link_libraries(cards PUBLIC ${CPPDSA_LIB})
target_link_libraries(animal PUBLIC ${CPPDSA_LIB})
target_link_libraries(template PUBLIC ${CPPDSA_LIB})
target_link_libraries(classTemplate PUBLIC ${CPPDSA_LIB})

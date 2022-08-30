cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

include_directories(/usr/local/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../bin)

find_library(CPPBOOK5_LIB cppBook5 HINTS /usr/local/lib/) # update here

# add_executable(test src/test.cpp)s
# target_link_libraries(test PUBLIC ${CPPBOOK5_LIB}) # update here
add_executable(starting src/starting.cpp)

target_link_libraries(starting PUBLIC ${CPPBOOK5_LIB}) # update here

add_executable(flow src/flowControl.cpp)

target_link_libraries(flow PUBLIC ${CPPBOOK5_LIB}) # update here

add_executable(io src/io.cpp)

target_link_libraries(io PUBLIC ${CPPBOOK5_LIB}) # update here

add_executable(pointer src/pointer.cpp)

target_link_libraries(pointer PUBLIC ${CPPBOOK5_LIB}) # update here

add_executable(function src/function.cpp)

target_link_libraries(function PUBLIC ${CPPBOOK5_LIB}) # update here

add_executable(classes src/classes.cpp)

target_link_libraries(classes PUBLIC ${CPPBOOK5_LIB}) # update here

add_executable(templates src/templates.cpp)

target_link_libraries(templates PUBLIC ${CPPBOOK5_LIB}) # update here

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    if(NOT DEFINED CXXTEST_TESTGEN_ARGS)
        set(CXXTEST_TESTGEN_ARGS --error-printer)
    endif()

    add_executable(runner src/runner.cpp)

    target_link_libraries(runner PUBLIC ${CPPBOOK5_LIB})
endif()

# update here
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
add_executable(meTesting src/meTesting.cpp)

target_link_libraries(meTesting PUBLIC
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_test(MyTest meTesting)

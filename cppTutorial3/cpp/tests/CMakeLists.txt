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

add_executable(multiDimArrays src/multiDimArrays.cpp)

target_link_libraries(multiDimArrays PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(myVector src/myVector.cpp)

target_link_libraries(myVector PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(bitManipulations src/bitManipulations.cpp)

target_link_libraries(bitManipulations PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(recursion src/recursion.cpp)

target_link_libraries(recursion PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(divideConquer src/divideConquer.cpp)

target_link_libraries(divideConquer PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(backtracking src/backtracking.cpp)

target_link_libraries(backtracking PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(spaceTime src/spaceTime.cpp)

target_link_libraries(spaceTime PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(oops src/oops.cpp)

target_link_libraries(oops PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(linkedLists src/linkedLists.cpp)

target_link_libraries(linkedLists PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(stacks src/stacks.cpp)

target_link_libraries(stacks PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(queues src/queues.cpp)

target_link_libraries(queues PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(binaryTrees src/binaryTrees.cpp)

target_link_libraries(binaryTrees PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(bst src/bst.cpp)

target_link_libraries(bst PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(heaps src/heaps.cpp)

target_link_libraries(heaps PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(hash src/hash.cpp)

target_link_libraries(hash PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(graph src/graph.cpp)

target_link_libraries(graph PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(dp src/dp.cpp)

target_link_libraries(dp PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(tries src/tries.cpp)

target_link_libraries(tries PUBLIC ${CPPTUTORIAL3_LIB})

add_executable(shoppingCart src/shoppingCart.cpp)

target_link_libraries(shoppingCart PUBLIC ${CPPTUTORIAL3_LIB})
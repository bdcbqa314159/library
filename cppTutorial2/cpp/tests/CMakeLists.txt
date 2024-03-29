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

add_executable(dynamicProg src/dynamicProg.cpp)

add_executable(arrays src/arrays.cpp)

add_executable(linkedList src/linkedList.cpp)
add_executable(stack src/stack.cpp)
add_executable(queue src/queue.cpp)
add_executable(bst src/bst.cpp)
add_executable(heap src/heap.cpp)
add_executable(hashTable src/hashTable.cpp)
add_executable(bfs src/bfs.cpp)
add_executable(dfs src/dfs.cpp)
add_executable(dijkstra src/dijkstra.cpp)
add_executable(bellmanFord src/bellmanFord.cpp)

target_link_libraries(test PUBLIC ${CPPTUTORIAL2_LIB}) #update here
target_link_libraries(recursion PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(search PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(backtracking PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(dynamicProg PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(linkedList PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(stack PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(queue PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(bst PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(heap PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(hashTable PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(bfs PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(dfs PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(dijkstra PUBLIC ${CPPTUTORIAL2_LIB})
target_link_libraries(bellmanFord PUBLIC ${CPPTUTORIAL2_LIB})


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

find_library(GAME1_LIB game1 HINTS /usr/local/lib/) # update here

add_executable(test src/test.cpp)

target_link_libraries(test PUBLIC ${GAME1_LIB}) # update here
target_link_libraries(test PUBLIC ${SDL2_LIBRARIES})

# target_link_libraries(headersInclude PUBLIC ${CPPTUTORIAL1_LIB})

# target_link_libraries(classes PUBLIC ${CPPTUTORIAL1_LIB})

# target_link_libraries(namespaces PUBLIC ${CPPTUTORIAL1_LIB})

# target_link_libraries(testingSDL PUBLIC ${CPPTUTORIAL1_LIB})
# target_link_libraries(testingSDL PUBLIC ${SDL2_LIBRARIES})

# target_link_libraries(particle PUBLIC ${CPPTUTORIAL1_LIB})
# target_link_libraries(particle PUBLIC ${SDL2_LIBRARIES})
cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cppTutorial1 VERSION 0.1.0) # update here

# Include dir
include_directories(/usr/local/include)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIB_DIR})

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/cppTutorial1_bits") # update here

# Source files
set(SOURCE_FILES
    ${PROJECT_INCLUDE_DIR}/test.hpp
    ${PROJECT_INCLUDE_DIR}/utils.hpp
    ${PROJECT_INCLUDE_DIR}/cat.hpp
    ${PROJECT_INCLUDE_DIR}/person.hpp
    ${PROJECT_INCLUDE_DIR}/testingSDL.hpp
    ${PROJECT_INCLUDE_DIR}/screen.hpp
    ${PROJECT_INCLUDE_DIR}/particle.hpp
    ${PROJECT_INCLUDE_DIR}/swarm.hpp
    ${PROJECT_INCLUDE_DIR}/templates.hpp
    ${PROJECT_INCLUDE_DIR}/bitmapFileHeader.hpp
    ${PROJECT_INCLUDE_DIR}/bitmapInfoHeader.hpp
    ${PROJECT_INCLUDE_DIR}/bitmap.hpp
    ${PROJECT_INCLUDE_DIR}/mandelbrot.hpp
    ${PROJECT_INCLUDE_DIR}/zoom.hpp
    ${PROJECT_INCLUDE_DIR}/zoomList.hpp
    ${PROJECT_INCLUDE_DIR}/fractalCreator.hpp
    ${PROJECT_INCLUDE_DIR}/rgb.hpp

    ${PROJECT_SOURCE_DIR}/test.cpp
    ${PROJECT_SOURCE_DIR}/utils.cpp
    ${PROJECT_SOURCE_DIR}/cat.cpp
    ${PROJECT_SOURCE_DIR}/person.cpp
    ${PROJECT_SOURCE_DIR}/testingSDL.cpp
    ${PROJECT_SOURCE_DIR}/screen.cpp
    ${PROJECT_SOURCE_DIR}/particle.cpp
    ${PROJECT_SOURCE_DIR}/swarm.cpp
    ${PROJECT_SOURCE_DIR}/bitmap.cpp
    ${PROJECT_SOURCE_DIR}/mandelbrot.cpp
    ${PROJECT_SOURCE_DIR}/zoomList.cpp
    ${PROJECT_SOURCE_DIR}/fractalCreator.cpp
    ${PROJECT_SOURCE_DIR}/rgb.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(cppTutorial1 SHARED ${SOURCE_FILES}) # update here
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# Include directories
target_include_directories(cppTutorial1 PRIVATE include/cppTutorial1_bits) # update here

# Install
install(TARGETS cppTutorial1 DESTINATION lib) # update here

# Install the headers
install(FILES include/cppTutorial1 DESTINATION include) # update here

# Create base directory
install(DIRECTORY include/cppTutorial1_bits DESTINATION include) # update here

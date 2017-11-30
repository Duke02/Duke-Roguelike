cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME DukeRoguelike)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARDS 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

file(GLOB SOURCE_FILES "src/*.cpp" "src/Duke/*.cpp")

file(GLOB INCLUDE_FILES "include/*.h*" "include/Duke/*.h*")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC "include" PUBLIC "include/Duke")

set(CMAKE_MODULE_PATH "cmakeModules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS REQUIRED system graphics window)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

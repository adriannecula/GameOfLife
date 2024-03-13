cmake_minimum_required(VERSION 3.22)
project(game_of_life_lib)

add_library(${PROJECT_NAME} STATIC)

file(GLOB SOURCES "./src/*cpp")

# Add source files
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

#Include directories for header file
target_include_directories(${PROJECT_NAME} PUBLIC include)	
include_directories(include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics )

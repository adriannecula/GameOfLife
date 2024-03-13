cmake_minimum_required(VERSION 3.22)


add_library(game_of_life_lib STATIC)

file(GLOB SOURCES "./src/*cpp")

# Add source files
target_sources(game_of_life_lib PRIVATE ${SOURCES})

#Include directories for header file
target_include_directories(game_of_life_lib PUBLIC include)	
include_directories(include)
target_link_libraries(game_of_life_lib PRIVATE sfml-graphics )

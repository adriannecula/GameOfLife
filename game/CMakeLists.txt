cmake_minimum_required(VERSION 3.22)
project(game_of_life_exe)

file(GLOB SOURCES "*cpp")
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics game_of_life_lib)

install(TARGETS ${PROJECT_NAME})


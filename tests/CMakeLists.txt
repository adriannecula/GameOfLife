cmake_minimum_required(VERSION 3.16)
project(game_of_life_tests)


add_executable(${PROJECT_NAME})

file(GLOB SOURCES *cpp)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

enable_testing()

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main PRIVATE game_of_life_lib)

install(TARGETS ${PROJECT_NAME})
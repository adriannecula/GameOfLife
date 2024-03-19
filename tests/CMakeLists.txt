cmake_minimum_required(VERSION 3.16)
project(game_of_life_tests)


add_executable(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES 
    LIST_DIRECTORIES TRUE
    ${PROJECT_SOURCE_DIR}/*cpp
    ${PROJECT_SOURCE_DIR}/helpers/*cpp

)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

enable_testing()

target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main PRIVATE game_of_life_lib)

include_directories(helpers)

install(TARGETS ${PROJECT_NAME})
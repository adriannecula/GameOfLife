file(GLOB SOURCES "*cpp")

project(GameOfLifeExe)
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics game_of_life_lib)

install(TARGETS ${PROJECT_NAME})


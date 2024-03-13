file(GLOB SOURCES "*cpp")

add_executable(GameOfLife)
target_sources(GameOfLife PRIVATE ${SOURCES})

target_link_libraries(GameOfLife PRIVATE sfml-graphics game_of_life_lib)

install(TARGETS GameOfLife)


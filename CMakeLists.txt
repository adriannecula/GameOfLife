cmake_minimum_required(VERSION 3.16)
project(GameOfLife LANGUAGES CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# Install SFML library
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)




# Fetch Google Test from GitHub
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make Google Test available
FetchContent_MakeAvailable(googletest)

add_subdirectory(game_of_life_lib)
add_subdirectory(game)
add_subdirectory(tests)

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_INSTALL_PREFIX})



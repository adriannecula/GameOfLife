cmake_minimum_required(VERSION 3.16)
project(GameOfLife LANGUAGES CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


#
file(GLOB SOURCES "src/*.cpp")

# Install SFML library
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)



add_executable(GameOfLife ${SOURCES})
target_link_libraries(GameOfLife PRIVATE sfml-graphics)
target_compile_features(GameOfLife PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET GameOfLife
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<BOOL:${ARCH_64BITS}>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:GameOfLife>

        VERBATIM)
endif()

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_INSTALL_PREFIX})

install(TARGETS GameOfLife)

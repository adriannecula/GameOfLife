cmake_minimum_required(VERSION 3.22)
project(game_of_life_exe)


add_executable(${PROJECT_NAME})

file(GLOB SOURCES "*cpp")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<BOOL:${ARCH_64BITS}>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>

        VERBATIM)
endif()


target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics game_of_life_lib)

install(TARGETS ${PROJECT_NAME})


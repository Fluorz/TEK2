cmake_minimum_required(VERSION 3.5)
project(IndieStudio)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS "-W")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include_directories(
        src
        irrlicht-1.8.4/include
        lua/include
)

link_directories(irrlicht-1.8.4/lib/Linux)
link_directories(lua/lib)

file(GLOB_RECURSE src src/*.cpp src/*.hpp)

set(EXECUTABLE_NAME bomberman)
add_executable(${EXECUTABLE_NAME}
        ${src}
        )

execute_process(
        COMMAND make
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/irrlicht-1.8.4/source/Irrlicht
)

execute_process(
        COMMAND make
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lua
)

target_link_libraries(${EXECUTABLE_NAME}
        Irrlicht
        GL
        Xxf86vm
        Xext
        X11
        lua
        )

OPTION(PACK
        "create .deb"
        OFF)

if (PACK)
    ADD_DEFINITIONS(-DPACK)

    add_custom_command(TARGET ${EXECUTABLE_NAME}
            POST_BUILD
            COMMAND cpack
            )

    install(TARGETS "${EXECUTABLE_NAME}"
            RUNTIME DESTINATION /usr/bin)

    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/media/
            DESTINATION /usr/bin/COP/media)

    set(GAME_NAME COP)

    set(CPACK_PACKAGE_FILE_NAME ${GAME_NAME})
    set(CPACK_PACKAGE_NAME ${GAME_NAME})
    set(CPACK_GENERATOR "DEB")
    set(CPACK_PACKAGE_VERSION_MAJOR "1")
    set(CPACK_PACKAGE_VERSION_MINOR "0")
    set(CPACK_PACKAGE_VERSION_PATCH "0")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "COP linux installer")
    set(CPACK_PACKAGE_DESCRIPTION "COP linux installer")
    set(CPACK_PACKAGE_CONTACT "cop@cybersoftcreation.fr")

    include(CPack)
endif (PACK)

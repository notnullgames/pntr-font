cmake_minimum_required(VERSION 3.16.3)

project(pntr-font-demo)

include(FetchContent)

INCLUDE_DIRECTORIES(PUBLIC ${CMAKE_SOURCE_DIR}/..)

# pntr
FETCHCONTENT_DECLARE(pntr GIT_REPOSITORY https://github.com/RobLoach/pntr.git GIT_TAG master)
FETCHCONTENT_MAKEAVAILABLE(pntr)

# libschrift font lib
# TODO: inline this in ptr-font.h
FETCHCONTENT_DECLARE(schrift GIT_REPOSITORY https://github.com/tomolt/libschrift.git GIT_TAG master)
FETCHCONTENT_MAKEAVAILABLE(schrift)
INCLUDE_DIRECTORIES(PUBLIC ${schrift_SOURCE_DIR})


# SDL
find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    add_executable(${PROJECT_NAME} example_sdl.c ${schrift_SOURCE_DIR}/schrift.c)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main pntr)
else()
    message(WARNING "SDL not found")
endif()



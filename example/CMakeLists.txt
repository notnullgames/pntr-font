cmake_minimum_required(VERSION 3.16.3)

project(pntr-font)

include(FetchContent)

INCLUDE_DIRECTORIES(PUBLIC ${CMAKE_SOURCE_DIR}/..)

# pntr
FETCHCONTENT_DECLARE(pntr GIT_REPOSITORY https://github.com/RobLoach/pntr.git GIT_TAG master)
FETCHCONTENT_MAKEAVAILABLE(pntr)

# SDL
find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    add_executable(${PROJECT_NAME} example_sdl.c)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main pntr)
else()
    message(WARNING "SDL not found")
endif()



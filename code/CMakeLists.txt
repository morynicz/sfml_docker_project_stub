cmake_minimum_required(VERSION 3.12)
project(sdlDocker CXX)
find_package(SFML REQUIRED window system graphics)


add_executable(main main.cpp)
target_compile_options(main PUBLIC -Wall -Wextra -pedantic -Werror)

target_link_libraries(main sfml-window sfml-system sfml-graphics)
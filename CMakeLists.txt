cmake_minimum_required(VERSION 3.14)
project(freq)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
PUBLIC
    include
)

target_sources(${PROJECT_NAME}
PUBLIC
    src/dict.cpp
    src/util.cpp
    main.cpp
)

add_compile_options(-Werror -Wall -pedantic -O2)

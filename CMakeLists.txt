cmake_minimum_required(VERSION 3.22.0)

project(RaceSimulator)

set(BINARY_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR}/bin")


add_subdirectory(lib)

add_subdirectory(app)
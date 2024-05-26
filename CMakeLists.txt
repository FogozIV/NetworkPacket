cmake_minimum_required(VERSION 3.28)
project(NetworkPacket VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.cpp")

file(GLOB_RECURSE HEADERS "include/*.h")

message(${SOURCES})

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

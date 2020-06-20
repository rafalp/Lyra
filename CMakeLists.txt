cmake_minimum_required(VERSION 2.8.11)
project(Lyra)

find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
file(GLOB SOURCES src/*.h src/*.cpp)

add_executable(Lyra ${SOURCES})

target_link_libraries(Lyra PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(Lyra PRIVATE nlohmann_json::nlohmann_json)

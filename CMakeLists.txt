cmake_minimum_required(VERSION 2.8.11)
project(Lyra)

include_directories(${SDL2_INCLUDE_DIRS})
set(EXTERNAL_LIB_HEADERS include)

find_package(nlohmann_json 3.2.0 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Add source files
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# Add header files
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(Lyra ${SOURCE_FILES})

target_link_libraries(Lyra PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(Lyra PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Lyra PRIVATE ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
target_include_directories(Lyra PRIVATE ${EXTERNAL_LIB_HEADERS})
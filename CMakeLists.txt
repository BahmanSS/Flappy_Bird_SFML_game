cmake_minimum_required(VERSION 3.28)
project(FlappyBirdProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set(SOURCES 
    src/Bird.cpp
    src/BirdCollider.cpp 
    src/BirdPipeCollider.cpp
    src/Counter.cpp 
    src/GameState.cpp 
    src/main.cpp
    src/MenuState.cpp 
    src/Pipe.cpp 
    src/PipeManager.cpp
)

add_executable(game ${SOURCES})
target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_features(game PRIVATE cxx_std_17)
target_link_libraries(game PRIVATE SFML::Graphics SFML::Audio)

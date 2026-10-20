cmake_minimum_required(VERSION 3.20)
project(cpp_web_app LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
 crow
 GIT_REPOSITORY https://github.com/CrowCpp/CCROW.git
 GIT_TAG v.1.2.1
)

FetchContent_MakeAvailable(Crow)

add_executable(cpp_web_app main.cpp)
target_link_libraries(cpp_web_app PRIVATE Crow::Crow)

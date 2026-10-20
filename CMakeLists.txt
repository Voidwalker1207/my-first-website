cmake_minimum_required(VERSION 3.20)
project(cpp_web_app CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# use the local crow directory cloned by Docker
add_subdirectory(vendor/crow)

add_executable(cpp_web_app main.cpp)
target_link_libraries(cpp_web_app PRIVATE Crow::Crow)

cmake_minimum_required(VERSION 3.5.0)

project(bin2hex VERSION 0.1.0 LANGUAGES C CXX)

add_executable(bin2hex bin2hex.cpp)

target_include_directories(bin2hex PRIVATE 3rdparty/argparse/include)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
cmake_minimum_required(VERSION 3.10)
project(api_consumer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(CURL REQUIRED)

add_subdirectory(external/json)

include_directories(include)
include_directories(${CURL_INCLUDE_DIRS})
include_directories(${nlohmann_json_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(api_consumer ${SOURCES})
target_link_libraries(api_consumer PRIVATE CURL::libcurl nlohmann_json::nlohmann_json)

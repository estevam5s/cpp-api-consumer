cmake_minimum_required(VERSION 3.10)

project(api_consumer_project VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_library(api_consumer src/api_consumer/api.cpp src/utils.cpp)

find_package(CURL REQUIRED)
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
    target_link_libraries(api_consumer PRIVATE ${CURL_LIBRARIES})
else()
    message(FATAL_ERROR "CURL not found")
endif()

add_executable(api_consumer_main src/api_consumer_main.cpp)
add_executable(teste_api_consumer tests/teste_api_consumer.cpp)

target_link_libraries(api_consumer_main PRIVATE api_consumer)
target_link_libraries(teste_api_consumer PRIVATE api_consumer)

cmake_minimum_required(VERSION 3.5)

project(TTBG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fpermissive -g")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

file(GLOB_RECURSE api_srcs "${CMAKE_SOURCE_DIR}/T.T.B.G-API/*.cpp")
file(GLOB_RECURSE api_hdrs "${CMAKE_SOURCE_DIR}/T.T.B.G-API/*.h")
include_directories("${CMAKE_SOURCE_DIR}/T.T.B.G-API/")
find_package(wxWidgets COMPONENTS aui base core gl REQUIRED)
include("${wxWidgets_USE_FILE}")

add_library(
    "${PROJECT_NAME}-API"
    ${api_srcs}
    ${api_hdrs}
)
target_link_libraries("${PROJECT_NAME}-API" ${wxWidgets_LIBRARIES})

file(GLOB_RECURSE gui_srcs "${CMAKE_SOURCE_DIR}/T.T.B.G/*.cpp")
file(GLOB_RECURSE gui_hdrs "${CMAKE_SOURCE_DIR}/T.T.B.G/*.h")

add_executable(
    "${PROJECT_NAME}"
    ${gui_srcs}
    ${gui_hdrs}
)
target_link_libraries("${PROJECT_NAME}" ${wxWidgets_LIBRARIES})
target_link_libraries("${PROJECT_NAME}" "${PROJECT_NAME}-API")


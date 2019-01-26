cmake_minimum_required(VERSION 3.5)

project(TTBG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fpermissive -g")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

##### COPIED PART
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Gui CONFIG REQUIRED)
#####

file(GLOB_RECURSE gui_srcs "${CMAKE_SOURCE_DIR}/T.T.B.G/*.cpp")
file(GLOB_RECURSE gui_hdrs "${CMAKE_SOURCE_DIR}/T.T.B.G/*.h")

add_executable(
    "${PROJECT_NAME}"
    ${gui_srcs}
    ${gui_hdrs}
)
target_link_libraries("${PROJECT_NAME}" Qt5::Widgets)
target_link_libraries("${PROJECT_NAME}" Qt5::Core)
target_link_libraries("${PROJECT_NAME}" Qt5::Gui)
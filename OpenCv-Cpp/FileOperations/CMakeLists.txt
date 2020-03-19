cmake_minimum_required(VERSION 2.8) 

# use Folder Name for All Basic Projects
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectId})

# To find and use OpenCV from system and attach its header location to project
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(NAME_SRC
    ${PROJECT_NAME}.cpp
)

link_directories( ${CMAKE_BINARY_DIR}/bin)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# To build program to executable
add_executable( ${PROJECT_NAME} ${NAME_SRC})

# To link executable with opencv library
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
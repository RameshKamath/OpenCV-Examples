cmake_minimum_required(VERSION 2.8) 

# use Full Name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${ProjectId})

add_subdirectory(FileOperations)
add_subdirectory(ColorSpaceConversion)
add_subdirectory(DrawingBasics)
add_subdirectory(VideoGrabber)
add_subdirectory(StaticFeatures)
add_subdirectory(DynamicFeatures)
add_subdirectory(ScalingOperations)
add_subdirectory(RotationOperations)

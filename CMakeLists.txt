cmake_minimum_required (VERSION 2.6)
project (GLUTCraft)
set (PROJECT_DIR .)
set (PROJECT_SOURCE_DIR "${PROJECT_DIR}/src")
set (PROJECT_INCLUDE_DIR "${PROJECT_DIR}/include")
include_directories ("${PROJECT_INCLUDE_DIR}")
add_executable (GLUTCraft "${PROJECT_SOURCE_DIR}/main.c")
# For windows
target_link_libraries (GLUTCraft opengl32 glu32 freeglut)
# For Linux
#target_link_libraries (GLUTCraft GL GLU glut)
install (TARGETS GLUTCraft DESTINATION bin)
install (FILES include/utils.h DESTINATION include)

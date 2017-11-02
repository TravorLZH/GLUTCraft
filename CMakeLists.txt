cmake_minimum_required (VERSION 2.6)
project (GLUTCraft)
set (PROJECT_DIR .)
set (PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set (PROJECT_BINARIES_DIR ${PROJECT_DIR}/bin)
set (PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
add_executable (GLUTCraft ${PROJECT_SOURCE_DIR}/main.c)
#find_library (opengl32 opengl)
#find_library (glu32 glu)
#find_library (freeglut freeglut-lib)
include_directories (${PROJECT_INCLUDE_DIR})
target_link_libraries (GLUTCraft
	opengl32
	glu32
	freeglut)
install (TARGETS GLUTCraft DESTINATION bin)
install (FILES include/utils.h DESTINATION include)

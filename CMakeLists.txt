cmake_minimum_required (VERSION 2.6)
project (GLUTCraft)
set (GL_LIBS GL GLU glut)
if(WIN32)
	set (GL_LIBS opengl32 glu32 freeglut)
	install (FILES README.md LICENSE DESTINATION ${CMAKE_INSTALL_PREFIX})
endif(WIN32)
set (PROJECT_DIR .)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set (PROJECT_SOURCE_DIR "${PROJECT_DIR}/src")
set (PROJECT_INCLUDE_DIR "${PROJECT_DIR}/include")
include_directories ("${PROJECT_INCLUDE_DIR}")
add_library (glutcraft-core SHARED "${PROJECT_SOURCE_DIR}/dimconv.c" "${PROJECT_SOURCE_DIR}/dbgscreen.c"
	"${PROJECT_SOURCE_DIR}/movement.c"
)
add_executable (glutcraft "${PROJECT_SOURCE_DIR}/main.c")
target_link_libraries(glutcraft-core ${GL_LIBS})
target_link_libraries(glutcraft ${GL_LIBS} glutcraft-core)
install (TARGETS glutcraft glutcraft-core
	RUNTIME DESTINATION bin
	LIBRARY	DESTINATION lib
	ARCHIVE DESTINATION lib
)
install (DIRECTORY include DESTINATION ${CMAKE_INSTALL_PREFIX})

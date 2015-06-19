cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

# Create folder to allocate cmake owner projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


project      (GlutApp)

set ( PROJECT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set ( PROJECT_SOURCE_DIR "${PROJECT_ROOT_DIR}/src")
set ( PROJECT_BINARY_DIR "${PROJECT_ROOT_DIR}/bin")
set ( PROJECT_SHADER_DIR "${PROJECT_ROOT_DIR}/shaders")

#include_directories	(${PROJECT_ROOT_DIR}/include)


#######################################################################
############################# SETUP GLEW ##############################
find_package(GLEW REQUIRED)
include_directories	(${GLEW_INCLUDE_DIR})
if (NOT EXISTS ${GLEW_LIBRARY_DIR})
	get_filename_component(GLEW_LIBRARY_DIR ${GLEW_LIBRARY} PATH [CACHE])
endif()
link_directories(${GLEW_LIBRARY_DIR})
#######################################################################

#######################################################################
############################ SETUP OPENGL ##############################
find_package(OpenGL REQUIRED)
include_directories	(${OPENGL_INCLUDE_DIR})
#######################################################################

#######################################################################
############################# SETUP GLUT ##############################
find_package(GLUT REQUIRED)
include_directories	(${GLUT_INCLUDE_DIR})
if (NOT EXISTS ${GLUT_LIBRARY_DIR})
	get_filename_component(GLUT_LIBRARY_DIR ${GLUT_LIBRARY} PATH [CACHE])
endif()
link_directories(${GLUT_LIBRARY_DIR})
#######################################################################



#######################################################################
#################### SETUP OUTPUT DIRECTORY ###########################
set( CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/lib_install )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} CACHE INTERNAL "Single Directory for all executables")
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} CACHE INTERNAL "Single Directory for all libraries")
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR} CACHE INTERNAL "Single Directory for all libraries")
#######################################################################


add_subdirectory (${PROJECT_SOURCE_DIR}/GlutApp)







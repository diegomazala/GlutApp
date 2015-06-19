#######################################################################
# Setting Target_Name as current folder name
get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)



set  (SOURCE_FILES		#GlutApp.cpp
						GlutWindow.cpp 
						GlutMain.cpp)

set  (HEADER_FILES		GlutApp.h 
						GlutWindow.h )



add_executable(
  ${TARGET_NAME}
  ${SOURCE_FILES}
  ${HEADER_FILES}
)

target_link_libraries (	
	${TARGET_NAME} 
	${OPENGL_LIBRARY} 
	${GLEW_LIBRARY} 
	${GLUT_LIBRARY}
)






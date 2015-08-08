cmake_minimum_required (VERSION 3.3)

project(EngineMk1)

set (EngineMk1_VERSION_MAJOR 0)
set (EngineMk1_VERSION_MINOR 0)
set (EngineMk1_VERSION_PATCH 1)

configure_file (
 	"${PROJECT_SOURCE_DIR}/src/config.h.in"
 	"${PROJECT_BINARY_DIR}/config.h"
)

include_directories(
	${PROJECT_BINARY_DIR}
	${PROJECT_SOURCE_DIR}/extern/cppformat
	${PROJECT_SOURCE_DIR}/extern/glfw/include
	${PROJECT_SOURCE_DIR}/extern/glm
	${PROJECT_SOURCE_DIR}/extern/glbinding/source/glbinding/include
)

# Compile GLFW
SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
SET(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")
add_subdirectory (extern/glfw)

# Compile cppformat
add_subdirectory ("extern/cppformat")

# Compile glbinding
add_subdirectory ("extern/glbinding")

add_definitions(-DGLFW_INCLUDE_NONE)

add_executable(EngineMk1 "src/main.cxx")
target_link_libraries (EngineMk1 cppformat glfw ${GLFW_LIBRARIES} glbinding)
cmake_minimum_required (VERSION 3.3)

project(EngineMk1)

set (EngineMk1_VERSION_MAJOR 0)
set (EngineMk1_VERSION_MINOR 1)

configure_file (
 	"${PROJECT_SOURCE_DIR}/config.h.in"
 	"${PROJECT_BINARY_DIR}/config.h"
)

include_directories(
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/extern/cppformat"
)

# Libraries we'd like to include...
add_subdirectory ("extern/cppformat")

add_executable(EngineMk1 "src/main.cxx")
target_link_libraries (EngineMk1 cppformat)
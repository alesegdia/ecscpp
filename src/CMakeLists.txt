set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# SET SOURCES AND STUFF
file(GLOB_RECURSE CPPs *.cpp)
file(GLOB_RECURSE HPPs *.h)

#set(SFML_STATIC_LIBRARIES TRUE)

# FIND LIBRARIES
find_package(SFML 2 COMPONENTS system window graphics network audio)
find_package(Thor 2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED)

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(INC_DIRs)
include_directories(${INC_DIRs})

# NAME THE TARGETS
add_executable(swonie ${CPPs} ${HPPs})

# OPENGL
if(OPENGL_FOUND)
	include_directories(${OPENGL_INCLUDE_DIR})
	target_link_libraries(swonie ${OPENGL_LIBRARIES})
endif(OPENGL_FOUND)

# SFML
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(swonie ${SFML_LIBRARIES})
	message("SFML FOUND!!")
	message(${SFML_LIBRARIES})
endif(SFML_FOUND)

# Thor
if(THOR_FOUND)
	include_directories(${THOR_INCLUDE_DIR})
	target_link_libraries(swonie ${THOR_LIBRARY})
endif(THOR_FOUND)

# Boost
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	target_link_libraries(swonie ${Boost_LIBRARIES})
endif(Boost_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)


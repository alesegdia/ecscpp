set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# SET SOURCES AND STUFF
file(GLOB_RECURSE CORE_SRC lib/core/*)
file(GLOB_RECURSE ECS_SRC lib/ecs/*)
file(GLOB_RECURSE TESTGAME_SRC game/testgame/*)

#set(SFML_STATIC_LIBRARIES TRUE)

# FIND LIBRARIES
find_package(SFML 2 COMPONENTS system window graphics network audio)
find_package(Thor 2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED)

# NAME THE TARGETS
add_executable(testgame ${CORE_SRC} ${ECS_SRC} ${TESTGAME_SRC})

include_directories(testgame lib)

if(OPENGL_FOUND AND SFML_FOUND AND Boost_FOUND)

	include_directories(${OPENGL_INCLUDE_DIR})
	include_directories(${SFML_INCLUDE_DIR})
	include_directories(${Boost_INCLUDE_DIRS})

	target_link_libraries(testgame ${OPENGL_LIBRARIES})
	target_link_libraries(testgame ${SFML_LIBRARIES})
	target_link_libraries(testgame ${Boost_LIBRARIES})

endif()

# Thor
if(THOR_FOUND)
	include_directories(${THOR_INCLUDE_DIR})
	target_link_libraries(swonie ${THOR_LIBRARY})
endif(THOR_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)


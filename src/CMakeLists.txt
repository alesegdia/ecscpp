set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# SET SOURCES AND STUFF
file(GLOB_RECURSE CORE_SRC lib/core/*)
file(GLOB_RECURSE ECS_SRC lib/ecs/*)
file(GLOB_RECURSE TESTGAME_SRC demo/testgame/*)
file(GLOB_RECURSE SHOOTGAME_SRC demo/shootgame/*)

#set(SFML_STATIC_LIBRARIES TRUE)

# FIND LIBRARIES
find_package(SFML 2 COMPONENTS system window graphics network audio)
find_package(Thor 2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED)
find_package(BOX2D REQUIRED)

add_library(fwcore ${CORE_SRC})
add_library(fwecs ${ECS_SRC})

# add_executable(testgame ${TESTGAME_SRC})
# target_link_libraries(testgame LINK_PUBLIC fwcore fwecs)

add_executable(shootgame ${SHOOTGAME_SRC})
target_link_libraries(shootgame LINK_PUBLIC fwcore fwecs)

# include_directories(testgame lib)
include_directories(shootgame lib)

if(OPENGL_FOUND AND SFML_FOUND AND Boost_FOUND AND BOX2D_FOUND)

	include_directories(${OPENGL_INCLUDE_DIR})
	include_directories(${SFML_INCLUDE_DIR})
	include_directories(${Boost_INCLUDE_DIRS})
	include_directories(${BOX2D_INCLUDE_DIR})

	# target_link_libraries(testgame ${OPENGL_LIBRARIES})
	# target_link_libraries(testgame ${SFML_LIBRARIES})
	# target_link_libraries(testgame ${Boost_LIBRARIES})

	target_link_libraries(shootgame ${OPENGL_LIBRARIES})
	target_link_libraries(shootgame ${SFML_LIBRARIES})
	target_link_libraries(shootgame ${Boost_LIBRARIES})
	target_link_libraries(shootgame ${BOX2D_LIBRARIES})

endif()

# Thor
if(THOR_FOUND)
	include_directories(${THOR_INCLUDE_DIR})
	target_link_libraries(swonie ${THOR_LIBRARY})
endif(THOR_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/lib)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# SET SOURCES AND STUFF
file(GLOB_RECURSE ECS_SRC lib/ecs/*)

add_library(fwecs ${ECS_SRC})

include_directories(fwecs lib)

set(RZTL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../module/rztl/include)

include_directories(fwecs ${RZTL_PATH})

file(GLOB_RECURSE ECS_TESTS ./tests/*.cpp)

# UNIT TESTS
foreach(unit_test ${ECS_TESTS})
	get_filename_component(unit_test_name ${unit_test} NAME_WE)
	add_executable(${unit_test_name} ${unit_test})
	include_directories(${unit_test_name} ${RZTL_PATH})
	target_link_libraries(${unit_test_name} LINK_PUBLIC fwecs)
	include_directories(${unit_test_name} lib)
	set_target_properties(${unit_test_name}
		PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin/tests)
endforeach()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/lib)


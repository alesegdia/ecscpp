set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# SET SOURCES AND STUFF
file(GLOB_RECURSE ECS_SRC lib/ecs/*)

add_library(fwecs ${ECS_SRC})

include_directories(fwecs lib)

set(RZTL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../module/rztl/include)

include_directories(fwecs ${RZTL_PATH})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/lib)


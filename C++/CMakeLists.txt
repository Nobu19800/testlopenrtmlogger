cmake_minimum_required(VERSION 3.1)

set(target TestLogger)
project(${target} CXX)

find_package(OpenRTM REQUIRED)



add_definitions(${OPENRTM_CFLAGS})
link_directories(${OPENRTM_LIBRARY_DIRS})

add_library(${target} SHARED ${target}.cpp ${target}.h)
target_link_libraries(${target} ${OPENRTM_LIBRARIES})
target_include_directories(${target} SYSTEM PRIVATE ${OPENRTM_INCLUDE_DIRS})
set_target_properties(${target} PROPERTIES PREFIX "")
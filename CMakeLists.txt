cmake_minimum_required(VERSION 3.0.0)
project(HS_Panel_Solver VERSION 0.1.0)

include(CTest)
enable_testing()

add_definitions(-std=c++14)



add_subdirectory (${CMAKE_CURRENT_LIST_DIR}/src)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

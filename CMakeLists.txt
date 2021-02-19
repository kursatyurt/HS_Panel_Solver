cmake_minimum_required(VERSION 3.0.0)
project(HS_Panel_Solver VERSION 0.1.0)

include(CTest)
enable_testing()

add_definitions(-std=c++14)



find_package(Armadillo REQUIRED)

include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(HS_Panel_Solver
       	"./src/HS_Solver.cpp"
        "./src/Point.cpp"
        "./src/Panel.cpp"
       	"./src/InitFromFile.cpp"
       	"./src/InitFromNaca.cpp"
       	"./src/BaseInitializer.cpp"
        "./src/Solver.cpp"
       	)



target_link_libraries(HS_Panel_Solver ${ARMADILLO_LIBRARIES})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


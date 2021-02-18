cmake_minimum_required(VERSION 3.0.0)
project(HS_Panel_Solver VERSION 0.1.0)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
add_executable(HS_Panel_Solver
       	"./main.cpp"
        "./point.cpp"
        "./panel.cpp"
       	"./InitFromFile.cpp"
       	"./InitFromNaca.cpp"
       	"./BaseInitializer.cpp"
        "./solver.cpp"
       	)

target_link_libraries(HS_Panel_Solver ${ARMADILLO_LIBRARIES})


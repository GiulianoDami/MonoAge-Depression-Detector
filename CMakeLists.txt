cmake_minimum_required(VERSION 3.10)
project(MonoAgeDepressionDetector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS asio)
find_package(Eigen3 REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/DepressionPredictor.cpp
    src/TelomereAnalyzer.cpp
    src/AgingPatternDetector.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    include
    ${Boost_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} 
    ${Boost_LIBRARIES}
)
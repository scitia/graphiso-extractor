set(PROJECT_NAME graphiso-extractor)

cmake_minimum_required(VERSION 3.5)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ARMADILLO_LIBRARY "C:\\armadillo\\lib")
set(ARMADILLO_INCLUDE_DIR "C:\\armadillo\\include")

find_package(MKL REQUIRED)

find_package(Armadillo REQUIRED)

set(SOURCES 
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} ${ARMADILLO_LIBRARIES} MKL::MKL)
include_directories(${ARMADILLO_INCLUDE_DIRS})

include(CTest)
enable_testing()
set(PROJECT_NAME graphiso-extractor)

cmake_minimum_required(VERSION 3.5)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ARMADILLO_LIBRARY "C:\\armadillo\\lib")
set(ARMADILLO_INCLUDE_DIR "C:\\armadillo\\include")
set(BOOST_ROOT "C:/local/boost_1_85_0")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(MKL REQUIRED)

find_package(Armadillo REQUIRED)

find_package(Boost 1.85 REQUIRED COMPONENTS 
    filesystem 
    system 
    program_options 
    serialization 
    chrono
    log
)

set(SOURCES 
    src/main.cpp
    src/application.cpp
    src/graphcharacteristics.cpp
    src/groundfile.cpp
    src/fileio.cpp
    src/gfile.cpp
    src/graphfile.cpp
    src/greader.cpp
    src/gwriter.cpp
    src/groundwriter.cpp
    src/groundreader.cpp
    src/graphreader.cpp
    src/graphwriter.cpp
    src/inireader.cpp
    src/graphconverter.cpp
    src/filesystemutils.cpp
    src/resourcelocation.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} ${ARMADILLO_LIBRARIES} MKL::MKL ${Boost_LIBRARIES})
include_directories(${ARMADILLO_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

include(CTest)
enable_testing()
cmake_minimum_required(VERSION 3.5)
project(sofar_isa)

set (CMAKE_CXX_STANDARD 11)
if(NOT WIN32)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -fPIC -Wno-deprecated-copy")
endif()

IF (NOT DEFINED BUILD_VERSION)
        SET(BUILD_VERSION "not set")
ENDIF()

ADD_DEFINITIONS(-DBUILD_VERSION="${BUILD_VERSION}")

set(Qt5Core_DIR /usr/local/opt/qt/lib/cmake/Qt5Core)
set(CMAKE_AUTOMOC ON)


# first
find_package(catkin REQUIRED COMPONENTS
roscpp
rospy
std_msgs
)


find_package(Qt5 COMPONENTS REQUIRED Core
Widgets
Quick
)


# second
catkin_package()



# third
include_directories(${catkin_INCLUDE_DIRS})

include_directories(

        ${Qt5Core_INCLUDE_DIRS}
        ${Qt5Quick_INCLUDE_DIRS}
        ${Qt5Widgets_INCLUDE_DIRS}
	${CMAKE_CURRENT_BINARY_DIR}
        ../build-sofar_isa-Desktop-Debug

        )

# qt5_wrap_ui(SOURCES src/menuwindow.ui src/welcome.ui)




# fourth
add_executable(sofar_isa_node src/main.cpp src/welcome.cpp src/menuwindow.cpp)


# fifth
target_link_libraries(sofar_isa_node
	${catkin_LIBRARIES}
        Qt5::Core
        Qt5::Quick
        Qt5::Widgets
        )





cmake_minimum_required(VERSION 3.24)
project(lab5)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/bin")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(lab5 main.cpp Elektroscooter.cpp Repository.cpp ScooterController.cpp ScooterUI.cpp  GUI.cpp ScooterUIWidgetAdmin.h ScooterUIWidgetAdmin.cpp ScooterUIWidgetClient.cpp)

target_link_libraries(lab5 PRIVATE Qt5::Widgets)
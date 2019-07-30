cmake_minimum_required(VERSION 3.1...3.15)

project(PeDAL VERSION 2.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

find_package (Qt5 COMPONENTS Core Widgets WebEngine WebEngineWidgets CONFIG REQUIRED)
include_directories("include/scintilla")
include_directories("include/PeDAL")
include_directories("include/lua")
include_directories("include/sol2")
add_subdirectory(src)

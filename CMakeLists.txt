cmake_minimum_required(VERSION 3.19)
project(ITCR_DatosII_ProyectoIII)

set(CMAKE_CXX_STANDARD 20)

add_executable(ITCR_DatosII_ProyectoIII main.cpp TECFS_Disk.cpp TECFS_Disk.h Book.cpp Book.h FileWatcher.cpp FileWatcher.h)
add_executable(HuffmanCode HuffmanCode.cpp)
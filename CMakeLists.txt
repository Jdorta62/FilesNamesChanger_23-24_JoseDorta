cmake_minimum_required(VERSION 3.12)
project(FileNameChanger)

# Configurar las versiones del lenguaje C y C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Configurar el compilador
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "c++")

# Agregar los archivos fuente de tu proyecto
set(SOURCES
    src/ErrorManageClass.cc
    src/FolderClass.cc
    src/FileClass.cc
    src/main.cc
)

# Agregar el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

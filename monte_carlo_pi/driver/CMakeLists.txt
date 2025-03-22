cmake_minimum_required(VERSION 3.14)

add_executable(mcpi_drv main.c)
target_link_libraries(mcpi_drv mcpi)

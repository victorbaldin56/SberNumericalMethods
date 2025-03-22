cmake_minimum_required(VERSION 3.14)

add_library(mcpi src/monte_carlo_pi.c)
target_include_directories(mcpi PUBLIC include)

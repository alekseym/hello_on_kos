cmake_minimum_required (VERSION 3.12)

project (hello)

# Initialize CMake library for KasperskyOS SDK.
include (platform)
initialize_platform ()

# Toolchain for work with NK-parser.
include (platform/nk)

nk_build_edl_files (env_edl_files NK_MODULE "env" EDL "${CMAKE_SOURCE_DIR}/resources/edl/Env.edl")


add_subdirectory (env)
add_subdirectory (hello)
add_subdirectory (einit)

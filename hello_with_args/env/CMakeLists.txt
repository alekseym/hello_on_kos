project (env)

# Toolchain for work with NK-parser.
include (platform/nk)

# Set compilation flags.
project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

add_executable (Env "src/env.c")
add_dependencies (Env env_edl_files)
target_link_libraries (Env ${env_SERVER_LIB})
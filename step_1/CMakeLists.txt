cmake_minimum_required (VERSION 3.20)
project (app)

include (GNUInstallDirs)

find_package(oatpp 1.3.0 REQUIRED)

add_library (${PROJECT_NAME}-config INTERFACE)

target_compile_features (${PROJECT_NAME}-config
  INTERFACE
    cxx_std_17
)

add_subdirectory (src)

install (
  TARGETS
    ${PROJECT_NAME}-exe
)

install (
  DIRECTORY
    site
  TYPE BIN
)

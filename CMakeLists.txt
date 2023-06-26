cmake_minimum_required (VERSION 3.20)
project (static_html_server)

# set (CMAKE_CXX_STANDARD 17)

find_package(oatpp 1.3.0 REQUIRED)

add_library (${PROJECT_NAME}-config INTERFACE)

target_compile_features (${PROJECT_NAME}-config
  INTERFACE
    cxx_std_17
)

add_subdirectory (src)

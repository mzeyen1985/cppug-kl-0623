cmake_minimum_required (VERSION 3.20)
project (app)

include (GNUInstallDirs)

set (APP_STATIC_HTML
  ${CMAKE_INSTALL_RUNSTATEDIR}/site
  CACHE PATH
  "static HTML path"
)

set (APP_DATABASE
  ${CMAKE_INSTALL_RUNSTATEDIR}/db
  CACHE PATH
  "database file location"
)

find_package (oatpp 1.3.0 REQUIRED)
find_package (oatpp-sqlite 1.3.0 REQUIRED)
find_package (oatpp-swagger 1.3.0 REQUIRED)

find_package (Threads REQUIRED)

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
    site/
  DESTINATION ${APP_STATIC_HTML}
)

install (
  DIRECTORY
    sql
  DESTINATION ${APP_DATABASE}
)

###################################################################################################
# app_component library
###################################################################################################

add_library (${PROJECT_NAME}-lib)

target_link_libraries (${PROJECT_NAME}-lib
  PUBLIC
    ${PROJECT_NAME}-config
    oatpp::oatpp
    oatpp::oatpp-sqlite
    Threads::Threads
    ${CMAKE_DL_LIBS}
)

target_include_directories (${PROJECT_NAME}-lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions (${PROJECT_NAME}-lib
  PUBLIC
    DATABASE_FILE="${CMAKE_INSTALL_PREFIX}/${APP_DATABASE}/db.sqlite"
    DATABASE_MIGRATIONS="${CMAKE_INSTALL_PREFIX}/${APP_DATABASE}/sql"
    STATIC_HTML="${CMAKE_INSTALL_PREFIX}/${APP_STATIC_HTML}"
)

target_sources (${PROJECT_NAME}-lib
  PRIVATE
    ErrorHandler.cpp
)

###################################################################################################
# app executable
###################################################################################################

add_executable (${PROJECT_NAME}-exe)

target_link_libraries (${PROJECT_NAME}-exe
  PRIVATE
    ${PROJECT_NAME}-lib
)

target_sources (${PROJECT_NAME}-exe
  PRIVATE
    app.cpp
)

###################################################################################################
# Subdirectories
###################################################################################################

add_subdirectory (service)

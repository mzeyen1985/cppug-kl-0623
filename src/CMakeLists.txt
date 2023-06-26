###################################################################################################
# app_component library
###################################################################################################

add_library (${PROJECT_NAME}-lib)

target_link_libraries (${PROJECT_NAME}-lib
  PUBLIC
    ${PROJECT_NAME}-config
    oatpp::oatpp
)

target_include_directories (${PROJECT_NAME}-lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

###################################################################################################
# app executable
###################################################################################################

add_executable (${PROJECT_NAME}-exe)

target_link_libraries (${PROJECT_NAME}-exe
  PRIVATE
    ${PROJECT_NAME}-lib
)

target_include_directories (${PROJECT_NAME}-exe
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources (${PROJECT_NAME}-exe
  PRIVATE
    app.cpp
)

###################################################################################################
# Subdirectories
###################################################################################################

add_subdirectory (controller)

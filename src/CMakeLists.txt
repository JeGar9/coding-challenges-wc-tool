configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h
)

# Add source files
set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ccwp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ccwp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/options.h
    ${CMAKE_CURRENT_SOURCE_DIR}/options.cpp
)

set(SOURCE_FILES ${SOURCE_FILES} PARENT_SCOPE)

# Create the main executable
add_executable(ccwc ${SOURCE_FILES})

set(LIBRARY_SOURCES
    my_lib.cpp
)

add_library(${CUSTOM_LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})

target_include_directories(${CUSTOM_LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${CMAKE_BINARY_DIR}/configuration/include
)

target_link_libraries(${CUSTOM_LIBRARY_NAME} PUBLIC
    spdlog::spdlog
)

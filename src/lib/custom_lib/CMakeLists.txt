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

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET ${CUSTOM_LIBRARY_NAME}
        ENABLE ${ENABLE_WARNINGS}
        AS_ERRORS ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif()

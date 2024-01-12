message(STATUS "Building ${EXECUTABLE_NAME} executable code")

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
    ${CUSTOM_LIBRARY_NAME}
    ${GTEST_SAMPLES_LIB}
    spdlog::spdlog
    cxxopts::cxxopts
    nlohmann_json::nlohmann_json
)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET ${EXECUTABLE_NAME}
        ENABLE ${ENABLE_WARNINGS}
        AS_ERRORS ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif()

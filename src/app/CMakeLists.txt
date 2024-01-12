message(STATUS "Building ${EXECUTABLE_NAME} executable code")

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME} PUBLIC
    ${CUSTOM_LIBRARY_NAME}
    nlohmann_json::nlohmann_json
    spdlog::spdlog
)

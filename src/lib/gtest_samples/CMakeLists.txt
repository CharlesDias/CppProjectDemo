set(LIBRARY_SOURCES
    sample1.cpp
)

add_library(${GTEST_SAMPLES_LIB} STATIC ${LIBRARY_SOURCES})

target_include_directories(${GTEST_SAMPLES_LIB} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

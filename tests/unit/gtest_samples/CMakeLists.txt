add_executable( ${GTEST_SAMPLES_TEST}
    sample1_unittest.cpp
)

target_link_libraries( ${GTEST_SAMPLES_TEST}
    ${GTEST_SAMPLES_LIB}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests( ${GTEST_SAMPLES_TEST} )

add_executable( ${CUSTOM_LIB_TEST}
    my_lib.cpp
)

target_link_libraries( ${CUSTOM_LIB_TEST}
    ${CUSTOM_LIBRARY_NAME}
   # ${ASSERT_MOCK}
   GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests( ${CUSTOM_LIB_TEST} )

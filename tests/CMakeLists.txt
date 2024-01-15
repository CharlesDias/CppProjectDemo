if(BUILD_TESTS)
    set(CUSTOM_LIB_TEST custom_lib_test)
    set(GTEST_SAMPLES_TEST gtest_samples_tests)

    add_subdirectory(unit)

    if(ENABLE_COVERAGE)
        set(COVERAGE_MAIN "coverage")

        set(COVERAGE_EXCLUDES
            "${PROJECT_SOURCE_DIR}/build/*"
            "${PROJECT_SOURCE_DIR}/cmake/*"
            "${PROJECT_SOURCE_DIR}/configuration/*"
            "${PROJECT_SOURCE_DIR}/dockerfile/*"
            "${PROJECT_SOURCE_DIR}/sensor_data/*"
            "${PROJECT_SOURCE_DIR}/src/app/*"
            "${PROJECT_SOURCE_DIR}/docs/*"
            "${PROJECT_SOURCE_DIR}/tests/*"
            "${PROJECT_SOURCE_DIR}/thridparty/*"
            "/usr/include/*"
        )

        set(COVERAGE_DEPENDENCIES
            ${CUSTOM_LIB_TEST}
            ${GTEST_SAMPLES_TEST}
        )

        setup_target_for_coverage_lcov(
            NAME ${COVERAGE_MAIN}
            EXECUTABLE ${COVERAGE_DEPENDENCIES}
            DEPENDENCIES ${COVERAGE_DEPENDENCIES}
        )
    endif()
endif()

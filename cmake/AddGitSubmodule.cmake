function(add_git_submodule dir tag)
    find_package(Git REQUIRED)

    # Check if the submodule directory already exists and has CMakeLists.txt
    if(NOT EXISTS ${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt)
        # Initialize and update the submodule
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive ${dir}
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

        # Checkout the specified tag
        if(NOT tag STREQUAL "")
            message(STATUS "Checking out tag ${tag} in submodule ${dir}")
            execute_process(COMMAND ${GIT_EXECUTABLE} checkout ${tag}
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
        endif()
    endif()

    # Add the submodule if CMakeLists.txt is present
    if(EXISTS ${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt)
        message(STATUS "Adding submodule ${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt")
        add_subdirectory(${dir})
    else()
        message(WARNING "Could not add: ${CMAKE_SOURCE_DIR}/${dir}/CMakeLists.txt")
    endif()
endfunction(add_git_submodule)

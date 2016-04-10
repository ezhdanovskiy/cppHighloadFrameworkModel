include(${CMAKE_SOURCE_DIR}/gmock/CMakeLibs.txt)

function(add_gmock_test target)
    message(STATUS "add_gmock_test(${target} ${ARGN})")
    add_executable(${target} ${ARGN})
    target_link_libraries(${target} gmock_main)
    add_test(${target} ${target} --gtest_output=xml:${target}_gtestReport.xml)
endfunction()

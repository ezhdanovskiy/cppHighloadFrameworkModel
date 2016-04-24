project(SwipeServer)

set(BIN_NAME swipe-server)

include(${CMAKE_SOURCE_DIR}/storages/CMakeLibs.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES
    src/main.cpp
    src/SwipeImpl.cpp
    )
add_executable(${BIN_NAME} ${SOURCE_FILES})
target_link_libraries(${BIN_NAME} UserModel ${STORAGE_LIBS})

add_subdirectory(test)

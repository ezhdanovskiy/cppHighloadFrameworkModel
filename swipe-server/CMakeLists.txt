project(SwipeServer)

set(BIN_NAME swipe-server)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES
    src/main.cpp
    src/Event.cpp
    src/Subscriptions.cpp
    )
add_executable(${BIN_NAME} ${SOURCE_FILES})
target_link_libraries(${BIN_NAME} UserStorage ContactsStorage EventStorage Models)

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TESTS_BIN app_chat_tests)
set(TESTS_SOURSES
    startup_tests.cpp
    test_request.cpp
    test_response.cpp
    test_datetime.cpp
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set_target_properties(${TESTS} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        LINK_LIBRARIES pthread
        COMPILE_OPTIONS "-std=c++17;-O2;-Wall;-Wextra;-Wpedantic"
)

add_executable(${TESTS_BIN}
    ${TESTS_SOURSES}
)
find_package(Boost REQUIRED COMPONENTS system date_time unit_test_framework REQUIRED)
target_link_libraries (${TESTS_BIN}
    ${Boost_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    ${PROTOCOL_LIB_NAME}
)
include_directories(
    ${Boost_INCLUDE_DIR}
    ${PROTOCOL_LIB_NAME}
)

add_test(NAME ${TESTS_BIN} COMMAND ${TESTS_BIN})

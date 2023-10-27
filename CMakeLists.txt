cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED true)

project(main)

cmake_policy(SET CMP0135 NEW)

# ADDING LIBS

add_library(COMPLEX 
    STATIC lib/complex/cpp/Complex.cpp
)

# ADDING MAIN EXECUTABLE FILE

add_executable(main
    src/main.cpp
)

# LINKING MAIN EXECUTABLE FILE WITH LIBS

target_link_libraries(main
    PUBLIC COMPLEX
)

# GOOGLETEST FRAMEWORK

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# TESTS

enable_testing()

add_executable(COMPLEX_TESTS
    test/ComplexTests.cpp
)

target_link_libraries(COMPLEX_TESTS
    PRIVATE COMPLEX
    PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(COMPLEX_TESTS)


# COPYING BINARIES TO BIN FOLDER

set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Добавление команды копирования файла в папку ./bin
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${BIN_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:main> ${BIN_DIR})


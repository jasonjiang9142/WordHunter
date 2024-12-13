cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  grid_test
  ./tests/grid_test.cpp
  ./src/grid.cpp 
)

add_executable(
  dictionary_test 
    ./tests/dictionary_test.cpp
    ./src/dictionary.cpp
)


add_executable(
  bfs_test 
    ./tests/bfs_test.cpp
    ./src/bfs.cpp
)

add_executable(
  dfs_test 
    ./tests/dfs_test.cpp
    ./src/dfs.cpp
)

target_link_libraries(
  grid_test
  GTest::gtest_main
)

target_link_libraries(
  dictionary_test 
  GTest::gtest_main
)

target_link_libraries(
  bfs_test 
  GTest::gtest_main
)

target_link_libraries(
  dfs_test 
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(grid_test)
gtest_discover_tests(dictionary_test )
gtest_discover_tests(bfs_test )
gtest_discover_tests(dfs_test )
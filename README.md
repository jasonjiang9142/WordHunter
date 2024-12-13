to be done



How to run unit test using gtest for cpp (Google test)

follow https://google.github.io/googletest/quickstart-cmake.html

for each test, create a new add executable 


add_executable(
  dictionary_test 
    ./tests/dictionary_test.cpp
    ./src/dictionary.cpp
)


then target link library 
target_link_libraries(
  dfs_test 
  GTest::gtest_main
)


then add gtest_discover_tests(executable)
gtest_discover_tests(grid_test)

how to run it 
mkdir build
cd build 
cmake ..
make
ctest or run individual executable ./grid_test (but have to make sure that we are in the build repostory first )
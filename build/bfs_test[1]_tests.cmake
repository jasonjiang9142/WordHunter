add_test([=[BfsTest.TestBfsWordFound]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsTest.TestBfsWordFound]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsTest.TestBfsWordFound]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BfsTest.TestBfsWordNotFound]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsTest.TestBfsWordNotFound]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsTest.TestBfsWordNotFound]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BfsTest.TestBfsEmptyGrid]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsTest.TestBfsEmptyGrid]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsTest.TestBfsEmptyGrid]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BfsTest.TestBfsSingleCellGrid]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsTest.TestBfsSingleCellGrid]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsTest.TestBfsSingleCellGrid]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BfsTest.TestBfsSameLetterGrid]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsTest.TestBfsSameLetterGrid]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsTest.TestBfsSameLetterGrid]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BfsWrapperTest.TestBfsWrapperValidWord]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsWrapperTest.TestBfsWrapperValidWord]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsWrapperTest.TestBfsWrapperValidWord]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BfsWrapperTest.TestBfsWrapperInvalidWord]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsWrapperTest.TestBfsWrapperInvalidWord]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsWrapperTest.TestBfsWrapperInvalidWord]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BfsWrapperTest.TestBfsWrapperEmptyWord]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsWrapperTest.TestBfsWrapperEmptyWord]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsWrapperTest.TestBfsWrapperEmptyWord]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BfsWrapperTest.TestBfsWrapperWordAlreadyFound]=]  /Users/jasonjiang/Desktop/wordhunt/build/bfs_test [==[--gtest_filter=BfsWrapperTest.TestBfsWrapperWordAlreadyFound]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BfsWrapperTest.TestBfsWrapperWordAlreadyFound]=]  PROPERTIES WORKING_DIRECTORY /Users/jasonjiang/Desktop/wordhunt/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  bfs_test_TESTS BfsTest.TestBfsWordFound BfsTest.TestBfsWordNotFound BfsTest.TestBfsEmptyGrid BfsTest.TestBfsSingleCellGrid BfsTest.TestBfsSameLetterGrid BfsWrapperTest.TestBfsWrapperValidWord BfsWrapperTest.TestBfsWrapperInvalidWord BfsWrapperTest.TestBfsWrapperEmptyWord BfsWrapperTest.TestBfsWrapperWordAlreadyFound)

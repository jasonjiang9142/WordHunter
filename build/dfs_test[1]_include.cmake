if(EXISTS "/Users/jasonjiang/Desktop/wordhunt/build/dfs_test[1]_tests.cmake")
  include("/Users/jasonjiang/Desktop/wordhunt/build/dfs_test[1]_tests.cmake")
else()
  add_test(dfs_test_NOT_BUILT dfs_test_NOT_BUILT)
endif()

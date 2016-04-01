function(algorithms_test)
  foreach(test ${ARGV})
    add_executable(${test} ${test}.cpp)
    add_test(${test} ${test})
  endforeach(test)
endfunction(algorithms_test)

algorithms_test(
  test_list
)

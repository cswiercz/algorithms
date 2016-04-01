function(algorithms_test)
  foreach(test ${ARGV})
    add_executable(${test} ${test}.c)
    target_link_libraries(${test} algorithms)
    add_test(${test} ${test})
  endforeach(test)
endfunction(algorithms_test)

algorithms_test(
  test_list
  test_tree
  test_queue
  test_sort
)

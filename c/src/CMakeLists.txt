set(LIBSRC
  list.c
  tree.c
  queue.c
)

add_library(algorithms ${LIBSRC})
install(TARGETS algorithms DESTINATION lib)

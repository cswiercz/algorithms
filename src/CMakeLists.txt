set(LIBSRC
  list.c
  tree.c
)

add_library(algorithms ${LIBSRC})
install(TARGETS algorithms DESTINATION lib)

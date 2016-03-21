set(LIBSRC
  list.c
)

add_library(algorithms ${LIBSRC})
install(TARGETS algorithms DESTINATION lib)

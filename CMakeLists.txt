cmake_minimum_required (VERSION 2.8.8)

project (algorithms)

enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/include")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)
add_subdirectory(test)
add_subdirectory(src)



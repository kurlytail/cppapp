
find_package(Boost COMPONENTS log REQUIRED)

add_library(redux INTERFACE)

target_include_directories(redux INTERFACE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(redux INTERFACE Boost::boost ${Boost_LOG_LIBRARY})

add_subdirectory(tests)
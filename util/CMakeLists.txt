
find_package(Boost COMPONENTS log REQUIRED)

add_library(util Factory.cc ClassFactory.cc)
target_include_directories(util PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(util PUBLIC Boost::boost ${Boost_LOG_LIBRARY})

#add_subdirectory(tests)
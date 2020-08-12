
include(GoogleTest)

add_executable(ReduxStoreTest ReduxStoreTest.cc)

target_link_libraries(ReduxStoreTest redux gtest_main)

gtest_add_tests(TARGET ReduxStoreTest)
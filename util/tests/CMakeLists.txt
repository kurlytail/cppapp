
include(GoogleTest)

add_executable(FactoryTest FactoryTest.cc)

target_link_libraries(FactoryTest util gtest_main)

gtest_add_tests(TARGET FactoryTest)
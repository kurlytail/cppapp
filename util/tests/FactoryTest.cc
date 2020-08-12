
#include "Factory.h"
#include "gtest/gtest.h"

class TestClass {
};

TEST(FactoryTest, FactoryCreate)
{
    bst::Factory::RegisterClass<TestClass>("Test");
    auto &a = bst::Factory::CreateObject<TestClass>("Test");
}

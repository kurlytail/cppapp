
#include "redux/Redux.h"
#include "gtest/gtest.h"

using namespace bst::redux;

TEST(ReduxStoreTest, ReduxStoreLifecycle)
{
    auto store =
        createStore(0, [](int oldState, std::string action) { return 0; });
}

TEST(ReduxStoreTest, ReduxStoreDispatch)
{
    auto store =
        createStore(0, [](int oldState, int action) { return 0xfeef; });
    store.dispatch(0);
    EXPECT_EQ(0xfeef, store.getState());
}

TEST(ReduxStoreTest, ReduxStoreDispatchClass)
{
    struct Application {
        int operator()(int, int) { return 0xfeef; }
    };

    auto store = createStore(0, Application());
    store.dispatch(0);
    EXPECT_EQ(0xfeef, store.getState());
}


#include <string>
#include <unordered_map>

#include "redux/Redux.h"
#include "gtest/gtest.h"

using namespace bst::redux;

TEST(ReduxStoreTest, ReduxStoreLifecycle)
{
    auto store = createStore<int, std::string>(
        0, [](int oldState, std::string action) { return 0; });
}

TEST(ReduxStoreTest, ReduxStoreDispatch)
{
    auto store = createStore<int, int>(
        0, [](int oldState, int action) { return 0xfeef; });
    store.dispatch(0);
    EXPECT_EQ(0xfeef, store.getState());
}

TEST(ReduxStoreTest, ReduxStoreDispatchClass)
{
    struct Application {
        int operator()(int, int) { return 0xfeef; }
    };

    auto store = createStore<int, int>(0, Application());
    store.dispatch(0);
    EXPECT_EQ(0xfeef, store.getState());
}

TEST(ReduxStoreTest, CombineReducers)
{
    using State = std::unordered_map<std::string, int>;
    auto application = combineReducers<State, int>({
        {"return_1", [](const int &oldState, const int action) { return 1; }},
        {"return_2", [](const int &oldState, const int action) { return 2; }},
    });

    auto store = createStore<State, int>({}, application);
    store.dispatch(0);
    EXPECT_EQ(store.getState().at("return_1"), 1);
    EXPECT_EQ(store.getState().at("return_2"), 2);
}

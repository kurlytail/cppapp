

#ifndef __BST_REDUX_H__
#define __BST_REDUX_H__

#include <list>
#include <string>
#include <type_traits>
#include <unordered_map>

namespace bst::redux {

template <typename State, typename Application> class Store {

  private:
    State state;

  public:
    void setState(const State &newState) { state = newState; }
    const State getState() const { return state; }

    template <typename Action> void dispatch(const Action &&action)
    {
        const auto newState = Application()(getState(), action);
        setState(newState);
    };

    Store(const State &s) : state(s) { ; }
};

template <typename State, typename Application>
auto createStore(const State &init, const Application &application)
{
    class Store<State, Application> store(init);
    return store;
}

} // namespace bst::redux

#endif
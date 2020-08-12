

#ifndef __BST_REDUX_H__
#define __BST_REDUX_H__

#include <functional>
#include <list>
#include <map>
#include <string>
#include <type_traits>
#include <utility>

#include "types/Reducers.h"

namespace bst::redux {

template <typename State = std::any, typename ActionType = std::any>
class Store {
  public:
    using Reducer =
        std::function<State(const State &, const Action<ActionType> &)>;

  private:
    State state;
    Reducer reducer;

  public:
    void setState(const State &newState) { state = newState; }
    const State getState() const { return state; }

    void dispatch(const Action<ActionType> &action)
    {
        const auto newState = reducer(getState(), action);
        setState(newState);
    };

    Store(const State &s, const Reducer &a) : state(s), reducer(a) { ; }
};

template <typename State = std::any, typename ActionType = std::any>
auto createStore(const State &init,
                 const typename Store<State, ActionType>::Reducer &reducer)
{
    class Store<State, ActionType> store(init, reducer);
    return store;
}

template <typename State = std::any, typename ActionType = std::any>
auto combineReducers(
    const std::map<std::string, std::function<typename State::mapped_type(
                                    const typename State::mapped_type &,
                                    const Action<ActionType> &)>> &&reducers)
{
    return [reducers = std::move(reducers)](const State &state,
                                            const Action<ActionType> &action) {
        State newState;
        bool changed = false;

        for (auto &pair : reducers) {
            auto &key = pair.first;
            typename State::mapped_type oldValue;

            try {
                oldValue = state.at(key);
            }
            catch (std::out_of_range) {
            }

            auto &&newValue = pair.second(oldValue, action);
            if (newValue != oldValue) {
                newState.insert(std::pair(key, newValue));
                changed = true;
            }
        }

        return changed ? newState : state;
    };
}

} // namespace bst::redux

#endif
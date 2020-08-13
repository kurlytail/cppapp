

#ifndef __BST_REDUX_H__
#define __BST_REDUX_H__

#include <functional>
#include <list>
#include <map>
#include <string>
#include <type_traits>
#include <utility>

#include "types/Reducers.h"
#include "types/Store.h"

namespace bst::redux {

template <typename S = std::any, typename T = std::any>
auto createStore(const S &init, const typename Store<S, T>::Reducer &reducer)
{
    class Store<S, T> store(init, reducer);
    return store;
}

template <typename S = std::any, typename T = std::any>
auto combineReducers(
    const std::map<std::string,
                   std::function<typename S::mapped_type(
                       const typename S::mapped_type &, const Action<T> &)>>
        &&reducers)
{
    return [reducers = std::move(reducers)](const S &state,
                                            const Action<T> &action) {
        S newState;
        bool changed = false;

        for (auto &pair : reducers) {
            auto &key = pair.first;
            typename S::mapped_type oldValue;

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
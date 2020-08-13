
#pragma once

#include <any>
#include <functional>
#include <type_traits>

#include "Actions.h"

namespace bst::redux {

template <typename S, typename T = std::any, typename A = AnyAction<T>,
          typename std::enable_if<
              std::is_convertible<A, Action<T>>::value>::type * = nullptr>
class Store {
  public:
    using Reducer = std::function<S(const S &, const A &)>;

  private:
    S state;
    Reducer reducer;

  public:
    void setState(const S &newState) { state = newState; }
    const S getState() const { return state; }

    void dispatch(const A &action)
    {
        const auto newState = reducer(getState(), action);
        setState(newState);
    };

    Store(const S &s, const Reducer &a) : state(s), reducer(a) { ; }
};

} // namespace bst::redux
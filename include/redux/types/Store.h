
#pragma once

#include <any>
#include <functional>
#include <type_traits>
#include <variant>

#include "Actions.h"
#include "Exceptions.h"
#include "Reducers.h"

namespace bst::redux {

template <typename S, typename A = AnyAction<>,
          typename std::enable_if<
              std::is_convertible<A, ActionBase>::value>::type * = nullptr>
struct Store {

    Reducer<S, A> currentReducer;
    S currentState;
    bool isDispatching = false;

    S getState()
    {
        if (isDispatching) {
            throw exception("You may not call store.getState() while the "
                            "reducer is executing. "
                            "The reducer has already received the state as "
                            "an argument. "
                            "Pass it down from the top reducer instead of "
                            "reading it from the store.");
        }

        return currentState;
    }

    template <typename D,
              typename std::enable_if<std::is_convertible<D, A>::value &&
                                      std::is_trivial<D>::value &&
                                      std::is_standard_layout<D>::value>::type
                  * = nullptr>
    D dispatch(D action)
    {
        if (isDispatching) {
            throw exception("Reducers may not dispatch actions.");
        }

        try {
            isDispatching = true;
            currentState = currentReducer(currentState, action);
        }
        catch (std::exception ex) {
            isDispatching = false;
            throw ex;
        }

        isDispatching = false;

        return action;
    }

    Store(Reducer<S, A> reducer) : currentReducer(reducer) { ; }
};

} // namespace bst::redux
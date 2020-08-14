#pragma once

#include <any>
#include <exception>
#include <string>
#include <type_traits>

#include "types/Actions.h"
#include "types/Reducers.h"

namespace bst::redux {

struct exception : std::exception {
    const std::string reason;
    exception(const std::string r = "unknown exception") : reason(r) { ; }
    const char *what() const noexcept { return reason.c_str(); }
};

template <typename S, typename A,
          typename std::enable_if<
              std::is_convertible<A, ActionBase>::value>::type * = nullptr>
Store<S, A> createStore(Reducer<S, A> reducer)
{
    return Store<S, A>(reducer);
}

} // namespace bst::redux
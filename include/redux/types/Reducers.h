
#pragma once

#include <any>
#include <type_traits>

#include "Actions.h"

namespace bst::redux {

template <
    typename S = std::any, typename T = std::any, typename A = AnyAction<T>,
    typename std::enable_if<std::is_convertible<A, Action<T>>::value>::type * =
        nullptr>
class Reducer {
  public:
    S operator()(S state, A action) { return S(); }
};

} // namespace bst::redux


#pragma once

#include <any>
#include <functional>
#include <type_traits>

#include "Actions.h"

namespace bst::redux {

template <typename S = std::any, typename A = AnyAction<>,
          typename std::enable_if<
              std::is_convertible<A, ActionBase>::value>::type * = nullptr>
using Reducer = std::function<S(S, A)>;

} // namespace bst::redux

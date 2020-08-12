

#ifndef __BST_REDUX_TYPES_ACTIONS_H__
#define __BST_REDUX_TYPES_ACTIONS_H__

#include <any>
#include <string>
#include <unordered_map>

namespace bst::redux {

using Action = std::any;

class AnyAction : public std::any,
                  public std::unordered_map<std::string, std::any> {
};

template <typename A, typename P> class ActionCreator {
    A operator()(std::initializer_list<P>);
};

template <typename A, typename P>
class ActionCreatorMapsObject
    : public std::unordered_map<std::string, ActionCreator<A, P>> {
};

} // namespace bst::redux

#endif
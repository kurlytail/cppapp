

#ifndef __BST_REDUX_TYPES_ACTIONS_H__
#define __BST_REDUX_TYPES_ACTIONS_H__

#include <any>
#include <string>
#include <unordered_map>

namespace bst::redux {

template <typename T = std::any> struct Action {
    T type;
    Action(T t) : type(t) { ; }
};

template <typename T>
class AnyAction : public Action<T>,
                  public std::unordered_map<std::string, std::any> {
};

template <typename A, typename P = std::vector<std::any>> class ActionCreator {
    A operator()(std::initializer_list<typename P::value_type>);
};

template <typename A, typename P>
class ActionCreatorMapsObject
    : public std::unordered_map<std::string, ActionCreator<A, P>> {
};

} // namespace bst::redux

#endif
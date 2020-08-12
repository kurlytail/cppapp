

#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <any>
#include <boost/log/trivial.hpp>
#include <string>
#include <unordered_map>

namespace bst {

template <class T> class ClassFactory {
  public:
    T &CreateObject() const { return *new T; }
};

class Factory {

  private:
    static std::unordered_map<std::string, std::any> objectDict;

  public:
    template <typename T> static T &CreateObject(const std::string &&className)
    {
        BOOST_LOG_TRIVIAL(info)
            << "Creating object of type " << className << std::endl;

        auto factory = std::any_cast<ClassFactory<T>>(objectDict.at(className));
        return factory.CreateObject();
    }

    template <typename T>
    static void RegisterClass(const std::string &&className)
    {
        BOOST_LOG_TRIVIAL(info)
            << "Registering type " << className << std::endl;

        objectDict[className] = new ClassFactory<T>();
    }
};

} // namespace bst

#endif
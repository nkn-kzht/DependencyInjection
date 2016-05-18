/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 */
#ifndef CPPDICON_CONTAINER_HPP_
#define CPPDICON_CONTAINER_HPP_

#include <memory>

namespace cppdicon {
class Container {
 public:
  Container() : _componentManager(*this), _singletonComponentManager(*this) {}
  ~Container() = default;
  template <class Component>
  std::unique_ptr<Component> create(const std::string& name) const {
    return _componentManager.create<Component>(name);
  }
  template <class SingletonComponent>
  std::weak_ptr<SingletonComponent> getInstance(const std::string& name) const {
    return _singletonComponentManager.getInstance<SingletonComponent>(name);
  }
 private:
  Container(const Container& obj) = delete;
  Container(Container&& obj) = delete;
  Container& operator=(const Container& obj) = delete;
  Container& operator=(Container&& obj) = delete;
  class ComponentManager {
   public:
    ComponentManager() = delete;
    explicit ComponentManager(const Container& container) : _container(container) {}
    ~ComponentManager() = default;
    template<class Component>
    std::unique_ptr<Component> create(const std::string& name) const {
      std::unique_ptr<Component> instUp(new Component());
      return std::move(instUp);
    }
   private:
    ComponentManager(const ComponentManager& obj) = delete;
    ComponentManager(ComponentManager&& obj) = delete;
    ComponentManager& operator=(const ComponentManager& obj) = delete;
    ComponentManager& operator=(ComponentManager&& obj) = delete;
    const Container& _container;
  };
  const ComponentManager _componentManager;
  class SingletonComponentManager {
   public:
    SingletonComponentManager() = delete;
    explicit SingletonComponentManager(const Container& container) : _container(container) {}
    ~SingletonComponentManager() = default;
    template<class Component>
    std::weak_ptr<Component> getInstance(const std::string& name) const {
      static std::shared_ptr<Component> instSp = std::make_shared<Component>();
      return instSp;
    }
   private:
    SingletonComponentManager(const SingletonComponentManager& obj) = delete;
    SingletonComponentManager(SingletonComponentManager&& obj) = delete;
    SingletonComponentManager& operator=(const SingletonComponentManager& obj) = delete;
    SingletonComponentManager& operator=(SingletonComponentManager&& obj) = delete;
    const Container& _container;
  };
  const SingletonComponentManager _singletonComponentManager;
};
} /* cppdicon */

#endif /* CPPDICON_CONTAINER_HPP_ */

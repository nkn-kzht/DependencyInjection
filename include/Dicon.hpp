/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 */
#ifndef INCLUDE_DICON_HPP_
#define INCLUDE_DICON_HPP_

#include <cppdicon/Container.hpp>

#include <ClientImpl.h>
#include <SupplierImpl.h>

namespace cppdicon {
template<>
std::unique_ptr<::IClient> Container::ComponentManager::create(
    const std::string& name) const {
  std::unique_ptr<::IClient> returnInstUp;
  if ("client" == name) {
    std::unique_ptr<::ClientImpl> instUp(
        new ::ClientImpl(_container.create<ISupplier>("supplier_hello")));
    returnInstUp = std::move(instUp);
  } else {
    std::unique_ptr<::ClientImpl> instUp(new ::ClientImpl);
  }
  return std::move(returnInstUp);
}
template<>
std::weak_ptr<::IClient> Container::SingletonComponentManager::getInstance(
    const std::string& name) const {
  std::shared_ptr<::IClient> returnInstWp;
  if ("client" == name) {
    static std::shared_ptr<::ClientImpl> instSp;
    if (!instSp) {
      instSp = std::make_shared<::ClientImpl>(
          _container.create<ISupplier>("supplier_bye"));
    }
    returnInstWp = instSp;
  } else {
    static std::shared_ptr<::ClientImpl> instSp;
    if (!instSp) {
      instSp = std::make_shared<::ClientImpl>();
    }
    returnInstWp = instSp;
  }
  return returnInstWp;
}

template<>
std::unique_ptr<::ISupplier> Container::ComponentManager::create(
    const std::string& name) const {
  std::unique_ptr<::ISupplier> returnInstUp;
  if ("supplier_hello" == name) {
    std::unique_ptr<::SupplierImpl> instUp(new ::SupplierImpl("hello"));
    returnInstUp = std::move(instUp);
  } else if ("supplier_bye" == name) {
    std::unique_ptr<::SupplierImpl> instUp(new ::SupplierImpl("bye"));
    returnInstUp = std::move(instUp);
  } else {
    std::unique_ptr<::SupplierImpl> instUp(new ::SupplierImpl());
    returnInstUp = std::move(instUp);
  }
  return std::move(returnInstUp);
}
template<>
std::weak_ptr<::ISupplier> Container::SingletonComponentManager::getInstance(
    const std::string& name) const {
  std::shared_ptr<::ISupplier> returnInstWp;
  if ("supplier_hello" == name) {
    static std::shared_ptr<::SupplierImpl> instSp;
    if (!instSp) {
      instSp = std::make_shared<::SupplierImpl>("hello");
    }
    returnInstWp = instSp;
  } else if ("supplier_bye" == name) {
    static std::shared_ptr<::SupplierImpl> instSp;
    if (!instSp) {
      instSp = std::make_shared<::SupplierImpl>("bye");
    }
    returnInstWp = instSp;
  } else {
    static std::shared_ptr<::SupplierImpl> instSp;
    if (instSp) {
      instSp = std::make_shared<::SupplierImpl>();
    }
    returnInstWp = instSp;
  }
  return returnInstWp;
}
} /* cppdicon */

class Dicon {
 public:
  Dicon() = default;
  ~Dicon() = default;
  template<class Component>
  std::unique_ptr<Component> create(const std::string& name) const {
    return _container.create<Component>(name);
  }
  template<class SingletonComponent>
  std::weak_ptr<SingletonComponent> getInstance(const std::string& name) const {
    return _container.getInstance<SingletonComponent>(name);
  }
 private:
  Dicon(const Dicon& obj) = delete;
  Dicon(Dicon&& obj) = delete;
  Dicon&
  operator=(const Dicon& obj) = delete;
  Dicon&
  operator=(Dicon&& obj) = delete;
  cppdicon::Container _container;
};

#endif /* INCLUDE_DICON_HPP_ */

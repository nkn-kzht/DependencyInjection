/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 */
#ifndef INCLUDE_CLIENTIMPL_H_
#define INCLUDE_CLIENTIMPL_H_

#include <IClient.h>
#include <memory>

class ISupplier;
class ClientImpl : public IClient {
 public:
  ClientImpl() = default;
  explicit ClientImpl(std::unique_ptr<ISupplier>&& supplierUp);
  virtual ~ClientImpl() = default;
  virtual void exec();
  void setSupplier(std::unique_ptr<ISupplier>&& sullierUp);
 private:
  ClientImpl(const ClientImpl& obj) = delete;
  ClientImpl(ClientImpl&& obj) = delete;
  ClientImpl& operator=(const ClientImpl& obj) = delete;
  ClientImpl& operator=(ClientImpl&& obj) = delete;
  std::unique_ptr<ISupplier> _supllierUp;
};

#endif /* INCLUDE_CLIENTIMPL_H_ */

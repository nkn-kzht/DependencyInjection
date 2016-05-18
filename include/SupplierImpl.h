/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 */
#ifndef INCLUDE_SUPPLIERIMPL_H_
#define INCLUDE_SUPPLIERIMPL_H_

#include <string>

#include <ISupplier.h>

class SupplierImpl : public ISupplier {
 public:
  SupplierImpl() = default;
  explicit SupplierImpl(const std::string& message);
  virtual ~SupplierImpl() = default;
  void setMessage(const std::string& message);
  virtual std::string exec();
 private:
  SupplierImpl(const SupplierImpl& obj) = delete;
  SupplierImpl(SupplierImpl&& obj) = delete;
  SupplierImpl& operator=(const SupplierImpl& obj) = delete;
  SupplierImpl& operator=(SupplierImpl&& obj) = delete;
  std::string _message;
};

#endif /* INCLUDE_SUPPLIERIMPL_H_ */

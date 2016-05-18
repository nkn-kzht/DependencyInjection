/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 */
#ifndef INCLUDE_ISUPPLIER_H_
#define INCLUDE_ISUPPLIER_H_

#include <string>

class ISupplier {
 public:
  ISupplier() = default;
  virtual ~ISupplier() = default;
  virtual std::string exec() = 0;
 private:
  ISupplier(const ISupplier& obj) = delete;
  ISupplier(ISupplier&& obj) = delete;
  ISupplier& operator=(const ISupplier& obj) = delete;
  ISupplier& operator=(ISupplier&& obj) = delete;
};

#endif /* INCLUDE_ISUPPLIER_H_ */

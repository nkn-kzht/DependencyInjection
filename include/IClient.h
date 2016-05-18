/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 */
#ifndef INCLUDE_ICLIENT_H_
#define INCLUDE_ICLIENT_H_

#include <string>

class IClient {
 public:
  IClient() = default;
  virtual ~IClient() = default;
  virtual void
  exec() = 0;
 private:
  IClient(const IClient& obj) = delete;
  IClient(IClient&& obj) = delete;
  IClient&
  operator=(const IClient& obj) = delete;
  IClient&
  operator=(IClient&& obj) = delete;
};

#endif /* INCLUDE_ICLIENT_H_ */

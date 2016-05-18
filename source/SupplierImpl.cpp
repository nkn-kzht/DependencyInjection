/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 *
 * $Author$
 * $Date$
 */

#include <IClient.h>
#include <SupplierImpl.h>

SupplierImpl::SupplierImpl(const std::string& message)
    : _message(message) {
}

void SupplierImpl::setMessage(const std::string& message) {
  _message = message;
}
std::string SupplierImpl::exec() {
  return _message;
}

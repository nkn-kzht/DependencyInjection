/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 *
 * $Author$
 * $Date$
 */

#include <ClientImpl.h>
#include <ISupplier.h>

#include <iostream>

ClientImpl::ClientImpl(std::unique_ptr<ISupplier>&& supplierUp)
: _supllierUp(std::move(supplierUp)) {}

void ClientImpl::exec() {
  std::cout << _supllierUp->exec() << std::endl;
  return;
}

void ClientImpl::setSupplier(std::unique_ptr<ISupplier>&& sullierUp) {
  _supllierUp = std::move(sullierUp);
}

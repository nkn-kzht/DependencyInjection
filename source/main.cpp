/**
 * Copyright (C) 2015 NEC Communication Systems. All Rights Reserved.
 *
 * $Author$
 * $Date$
 */

#include <iostream>
#include <string>

#include <Dicon.hpp>
#include <IClient.h>

int main() {
  try {
    Dicon container;
    std::unique_ptr<IClient> clientUp(container.create<IClient>("client"));
    std::weak_ptr<IClient> clientWp(container.getInstance<IClient>("client"));
    clientUp->exec();
    clientWp.lock()->exec();
  } catch (...) {
    std::cout << "不明なエラー" << std::endl;
  }
  return 0;
}

/*
 * Copyright (c) 2018-present, Frederick Emmott.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the LICENSE file
 * in the root directory of this source tree.
 */

#pragma once

#include "MessageInterface.h"

#include <asio.hpp>

class TCPConnection : public MessageInterface {
 public:
  TCPConnection(asio::io_context* ctx);

  void startWaitingForMessage();

  void sendMessage(const std::string& message);
  asio::ip::tcp::socket& socket();

 private:
  void readyRead();
  asio::ip::tcp::socket mSocket;
};

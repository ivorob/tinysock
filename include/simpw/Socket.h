#pragma once

#include "SocketApi.h"

namespace simpw::network {

class Socket final {
public:
    Socket();
    Socket(SocketApi socketEngine);
    Socket(int sockfd);
    Socket(const Socket&) = delete;
    Socket(Socket&&);
    Socket& operator=(const Socket&) = delete;
    Socket& operator=(Socket&&);
    ~Socket();

    operator bool() const;
    int native();
private:
    int sockfd = -1;
    SocketApi engine;
};

}

#include "Socket.h"

namespace simpw::network {

Socket::Socket() {
}

Socket::Socket(SocketApi socketEngine)
  : engine(socketEngine)
  , sockfd(socketEngine.create()) {
}

Socket::Socket(int sockfd)
  : sockfd(sockfd) {
}

Socket::Socket(Socket&& other)
  : engine(other.engine)
  , sockfd(other.sockfd) {
    other.sockfd = -1;
}

Socket& Socket::operator=(Socket&& other) {
    return *this;
}

Socket::~Socket() {
    if (operator bool()) {
        engine.close(this->sockfd);
    }
}

Socket::operator bool() const {
    return this->sockfd != -1;
}

int Socket::native() {
    return this->sockfd;
}

}

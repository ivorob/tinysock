#include <sys/socket.h>
#include <unistd.h>

#include "SocketApi.h"

namespace simpw::network {

SocketApi& socketApi() {
    static SocketApi api = {
        .create = std::bind(::socket, PF_INET, SOCK_STREAM, TCP);
        .close = ::close
    };
    return api;
}

}

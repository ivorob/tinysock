#include "SocketAddress.h"

namespace simpw::network {

SocketAddress::SocketAddress(std::string address) {
    if (!address.starts_with("tcp://")) {
        throw std::runtime_error("Invalid address");
    }
}

}

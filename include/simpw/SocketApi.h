#pragma once

#include <functional>

namespace simpw::network {

struct SocketApi {
    std::function<int()> create;
    std::function<int(int)> close;
};

SocketApi& socketApi();

}

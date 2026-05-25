#pragma once

#include "Socket.h"

namespace simpw::network {

class AbstractSocketFactory {
public:
    virtual ~AbstractSocketFactory() = default;
    virtual Socket create() = 0;
};

}

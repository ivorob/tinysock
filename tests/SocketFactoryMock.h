#pragma once

#include <gmock/gmock.h>
#include "SocketFactory.h"

class SocketFactoryMock : 
    public simpw::network::AbstractSocketFactory {
public:
    MOCK_METHOD(simpw::network::Socket, create, ());
};

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Socket.h"
#include "SocketApi.h"

using namespace simpw::network;

namespace {

SocketApi makeSocketApi(
    int sockfd,
    std::function<int(int)> close = [](int){ return 0; }
) {
    SocketApi socketApi = {
        .create = [sockfd]() { return sockfd; },
        .close = close
    };
    return socketApi;
}

}

TEST(SocketTest, construction_is_succeeded) {
    // Arrange
    auto socketApi = makeSocketApi(1);

    // Act
    Socket socket(socketApi);

    // Assert
    ASSERT_EQ(1, socket.native());
    ASSERT_TRUE(socket);
}

TEST(SocketTest, moving_socket_is_succeeded) {
    // Arrange
    Socket socket(makeSocketApi(1));

    // Act
    auto movedSocket = std::move(socket);

    // Assert
    ASSERT_TRUE(movedSocket);
    ASSERT_FALSE(socket);
    ASSERT_EQ(-1, socket.native());
    ASSERT_EQ(1, movedSocket.native());
}

TEST(SocketTest, socket_is_closed_on_destruction) {
    // Arrange
    bool isClosed = false;
    SocketApi socketApi = makeSocketApi(1, [&isClosed](int) {
            isClosed = true;
            return 0;
        }
    );

    // Act
    { 
        Socket socket(socketApi);
    }

    // Assert
    ASSERT_TRUE(isClosed);
}

TEST(SocketTest, socket_bind_is_success) {
    // Arrange
    SocketApi socketApi = makeSocketApi(1);
    // Act
}

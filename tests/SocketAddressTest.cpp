#include <gtest/gtest.h>
#include "SocketAddress.h"

using namespace simpw::network;

namespace {

struct sockaddr_in makeAddress(std::string host, uint16_t port) {
}

}

TEST(SocketAddressTest, there_is_no_exception_during_valid_construction) {
    // Arrange
    const std::string address = "tcp://0.0.0.0:8443";

    // Act
    bool hasException = [&address]() {
        try {
            SocketAddress socketAddress(address);
        } catch (...) {
            return true;
        }
        return false;
    }();

    // Assert
    ASSERT_FALSE(hasException);
}

TEST(SocketAddressTest, there_is_exception_during_invalid_construction) {
    // Arrange
    const std::string address = "0.0.0.0:8443";

    // Act
    bool hasException = [&address]() {
        try {
            SocketAddress socketAddress(address);
        } catch (...) {
            return true;
        }

        return false;
    }();

    // Assert
    ASSERT_TRUE(hasException);
}

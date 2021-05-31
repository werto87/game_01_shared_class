#include "game_01_shared_class/serialization.hxx"
#include <catch2/catch.hpp>

namespace test
{

TEST_CASE ("hello world", "[test]")
{
  auto joinChannel = shared_class::JoinChannel{};
  joinChannel.channel = "some channel xD";
  std::cout << toJson (joinChannel) << std::endl;
  auto testObject = toObject<shared_class::JoinChannel> (toJson (joinChannel));
  REQUIRE (testObject.channel == "some channel xD");
}

}

#ifndef A454B6F4_5E02_4669_955C_18F207EE36D6
#define A454B6F4_5E02_4669_955C_18F207EE36D6

#include "confu_boost/confuBoost.hxx"
#include <cstddef>
#include <map>
#include <string>
#include <variant>

BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannel, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannelSuccess, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannelError, (std::string, channel) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccount, (std::string, accountName) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccountSuccess, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccountError, (std::string, accountName) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAccount, (std::string, accountName) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAccountSuccess, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAccountError, (std::string, accountName) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LogoutAccount, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LogoutAccountSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LogoutAccountError, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), BroadCastMessage, (std::string, channel) (std::string, message))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), BroadCastMessageSuccess, (std::string, channel) (std::string, message))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), BroadCastMessageError, (std::string, channel) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveChannel, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveChannelSuccess, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveChannelError, (std::string, channel) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), Message, (std::string, fromAccount) (std::string, channel) (std::string, message))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateGameLobby, (std::string, name) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateGameLobbySuccess, (std::string, name))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateGameLobbyError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinGameLobby, (std::string, name) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinGameLobbySuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinGameLobbyError, (std::string, name) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), UserInGameLobby, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), UsersInGameLobby, (std::string, name) (std::vector<shared_class::UserInGameLobby>, users) (size_t, maxUserSize))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), SetMaxUserSizeInCreateGameLobby, (std::string, createGameLobbyName) (size_t, maxUserSize))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), SetMaxUserSizeInCreateGameLobbyError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), MaxUserSizeInCreateGameLobby, (size_t, maxUserSize))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveGameLobby, )

BOOST_SERIALIZATION_BOILER_PLATE (shared_class::JoinChannel)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::JoinChannelSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::JoinChannelError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateAccount)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateAccountSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateAccountError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LoginAccount)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LoginAccountSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LoginAccountError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::BroadCastMessage)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::BroadCastMessageSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::BroadCastMessageError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LeaveChannel)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LeaveChannelSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LeaveChannelError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::Message)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LogoutAccount)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LogoutAccountSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LogoutAccountError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateGameLobby)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateGameLobbySuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateGameLobbyError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::JoinGameLobby)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::JoinGameLobbySuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::JoinGameLobbyError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::UserInGameLobby)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::UsersInGameLobby)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::SetMaxUserSizeInCreateGameLobby)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::MaxUserSizeInCreateGameLobby)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::SetMaxUserSizeInCreateGameLobbyError)

#endif /* A454B6F4_5E02_4669_955C_18F207EE36D6 */

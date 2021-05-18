#ifndef A454B6F4_5E02_4669_955C_18F207EE36D6
#define A454B6F4_5E02_4669_955C_18F207EE36D6

#include "confu_boost/confuBoost.hxx"
#include <boost/hana/assert.hpp>
#include <boost/hana/at_key.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/find.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/optional.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>
#include <cstddef>
#include <durak/game.hxx>
#include <map>
#include <string>
#include <variant>

BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannel, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannelSuccess, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannelError, (std::string, channel) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccount, (std::string, accountName) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccountCancel, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccountSuccess, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccountError, (std::string, accountName) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAccount, (std::string, accountName) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAccountCancel, )
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
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveGameLobbySuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveGameLobbyError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), WantToRelog, (std::string, accountName) (std::string, destination))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), RelogTo, (bool, wantsToRelog))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), RelogToSuccess, (bool, wantsToRelog))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), RelogToError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateGame, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateGameError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), StartGame, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttack, (std::vector<durak::Card>, cards))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefend, (durak::Card, cardToBeat) (durak::Card, card))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackPass, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackPassSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAttackPassError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAssistPass, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAssistPassSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAssistPassError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakdefendPass, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakdefendPassSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakdefendPassError, (std::string, error))

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
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LeaveGameLobby)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LeaveGameLobbySuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LeaveGameLobbyError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::WantToRelog)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::RelogTo)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::RelogToError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::RelogToSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateAccountCancel)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::LoginAccountCancel)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateGame)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::StartGame)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::CreateGameError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAttack)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakDefend)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackPass)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackPassSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackPassError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAssistPass)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAssistPassSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakAssistPassError)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakdefendPass)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakdefendPassSuccess)
BOOST_SERIALIZATION_BOILER_PLATE (shared_class::DurakdefendPassError)

// clang-format off
namespace shared_class{
static boost::hana::tuple<
JoinChannel,
JoinChannelSuccess,
JoinChannelError,
CreateAccount,
CreateAccountSuccess,
CreateAccountError,
LoginAccount,
LoginAccountSuccess,
LoginAccountError,
BroadCastMessage,
BroadCastMessageSuccess,
BroadCastMessageError,
LeaveChannel,
LeaveChannelSuccess,
LeaveChannelError,
Message,
LogoutAccount,
LogoutAccountSuccess,
LogoutAccountError,
CreateGameLobby,
CreateGameLobbySuccess,
CreateGameLobbyError,
JoinGameLobby,
JoinGameLobbySuccess,
JoinGameLobbyError,
UserInGameLobby,
UsersInGameLobby,
SetMaxUserSizeInCreateGameLobby,
MaxUserSizeInCreateGameLobby,
SetMaxUserSizeInCreateGameLobbyError,
LeaveGameLobby,
LeaveGameLobbySuccess,
LeaveGameLobbyError,
WantToRelog,
RelogTo,
RelogToError,
RelogToSuccess,
CreateAccountCancel,
LoginAccountCancel,
CreateGame,
StartGame,
CreateGameError,
DurakAttack,
DurakAttackSuccess,
DurakAttackError,
DurakDefend,
DurakDefendSuccess,
DurakDefendError,
DurakAttackPass,
DurakAttackPassSuccess,
DurakAttackPassError,
DurakAssistPass,
DurakAssistPassSuccess,
DurakAssistPassError,
DurakdefendPass,
DurakdefendPassSuccess,
DurakdefendPassError,
durak::GameData
  >  const sharedClasses{};
}
// clang-format on
#endif /* A454B6F4_5E02_4669_955C_18F207EE36D6 */

#ifndef A454B6F4_5E02_4669_955C_18F207EE36D6
#define A454B6F4_5E02_4669_955C_18F207EE36D6

#include <boost/algorithm/string.hpp>
#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/adapted/struct/define_struct.hpp>
#include <boost/fusion/algorithm/query/count.hpp>
#include <boost/fusion/functional.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/algorithm.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/count.hpp>
#include <boost/fusion/include/define_struct.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic_fwd.hpp>
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
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/range_c.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cstddef>
#include <durak/game.hxx>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <variant>

template <class Archive, typename T>
void
serializationHelper (Archive &ar, T &t)
{
  boost::fusion::for_each (boost::mpl::range_c<unsigned, 0, boost::fusion::result_of::size<T>::value> (), [&] (auto index) { ar &cereal::make_nvp (boost::fusion::extension::struct_member_name<T, index>::call (), boost::fusion::at_c<index> (t)); });
}

// use SERIALIZATION_BOILER_PLATE in a namespace
// clang-format off
#ifndef SERIALIZATION_BOILER_PLATE
#define SERIALIZATION_BOILER_PLATE(NAMESPACE_WITH_TYPE)                                     \
void prologue(cereal::JSONOutputArchive &ar, const NAMESPACE_WITH_TYPE &) {                 \
  auto fullName = std::vector<std::string>{};                                               \
  auto typeWithNamespace = boost::typeindex::type_id<NAMESPACE_WITH_TYPE>().pretty_name();  \
  boost::algorithm::split(fullName, typeWithNamespace, boost::is_any_of("::"));             \
  ar.setNextName(fullName.back().c_str());                                                  \
  ar.startNode();                                                                           \
}                                                                                           \
void epilogue(cereal::JSONOutputArchive &ar, const NAMESPACE_WITH_TYPE &) {                 \
  ar.finishNode();                                                                          \
}                                                                                           \
  template <class Archive>                                                                  \
  void                                                                                      \
  serialize (Archive &ar, NAMESPACE_WITH_TYPE &t)                                           \
  {                                                                                         \
    serializationHelper (ar, t);                                                            \
  }                                                                                         \

#endif
// clang-format on

BOOST_FUSION_DEFINE_STRUCT ((shared_class), MyClass, (int, x) (int, y) (int, z))
namespace shared_class
{
SERIALIZATION_BOILER_PLATE (shared_class::MyClass)
} // namespace shared_class

template <typename T>
std::stringstream
toJson (T const &t)
{
  std::stringstream ss{}; // any stream can be used
  {
    cereal::JSONOutputArchive oarchive (ss); // Create an output archive
    oarchive (t);
  }
  return ss;
}

// TODO think about search for the type by name in some lookup so we dont have
// to specify the template parameter
template <typename T>
T
toObject (std::string const &objectAsString)
{
  std::stringstream ss{};
  T t{};
  {
    ss << objectAsString;
    cereal::JSONInputArchive iarchive (ss);
    T t{};
    iarchive (t);
  }
  return t;
}

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
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendPass, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendPassSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendPassError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAskDefendWantToTakeCards, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAskDefendWantToTakeCardsAnswer, (bool, answer))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAskDefendWantToTakeCardsAnswerSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAskDefendWantToTakeCardsAnswerError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoYouWantToAddCards, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoYouWantToAddCardsAnswer, (bool, answer))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoneAddingCards, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoneAddingCardsSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakDefendWantsToTakeCardsFromTableDoneAddingCardsError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakGameOverWon, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakGameOverLose, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakGameOverDraw, )

SERIALIZATION_BOILER_PLATE (shared_class::JoinChannel)
SERIALIZATION_BOILER_PLATE (shared_class::JoinChannelSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::JoinChannelError)
SERIALIZATION_BOILER_PLATE (shared_class::CreateAccount)
SERIALIZATION_BOILER_PLATE (shared_class::CreateAccountSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::CreateAccountError)
SERIALIZATION_BOILER_PLATE (shared_class::LoginAccount)
SERIALIZATION_BOILER_PLATE (shared_class::LoginAccountSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::LoginAccountError)
SERIALIZATION_BOILER_PLATE (shared_class::BroadCastMessage)
SERIALIZATION_BOILER_PLATE (shared_class::BroadCastMessageSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::BroadCastMessageError)
SERIALIZATION_BOILER_PLATE (shared_class::LeaveChannel)
SERIALIZATION_BOILER_PLATE (shared_class::LeaveChannelSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::LeaveChannelError)
SERIALIZATION_BOILER_PLATE (shared_class::Message)
SERIALIZATION_BOILER_PLATE (shared_class::LogoutAccount)
SERIALIZATION_BOILER_PLATE (shared_class::LogoutAccountSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::LogoutAccountError)
SERIALIZATION_BOILER_PLATE (shared_class::CreateGameLobby)
SERIALIZATION_BOILER_PLATE (shared_class::CreateGameLobbySuccess)
SERIALIZATION_BOILER_PLATE (shared_class::CreateGameLobbyError)
SERIALIZATION_BOILER_PLATE (shared_class::JoinGameLobby)
SERIALIZATION_BOILER_PLATE (shared_class::JoinGameLobbySuccess)
SERIALIZATION_BOILER_PLATE (shared_class::JoinGameLobbyError)
SERIALIZATION_BOILER_PLATE (shared_class::UserInGameLobby)
SERIALIZATION_BOILER_PLATE (shared_class::UsersInGameLobby)
SERIALIZATION_BOILER_PLATE (shared_class::SetMaxUserSizeInCreateGameLobby)
SERIALIZATION_BOILER_PLATE (shared_class::MaxUserSizeInCreateGameLobby)
SERIALIZATION_BOILER_PLATE (shared_class::SetMaxUserSizeInCreateGameLobbyError)
SERIALIZATION_BOILER_PLATE (shared_class::LeaveGameLobby)
SERIALIZATION_BOILER_PLATE (shared_class::LeaveGameLobbySuccess)
SERIALIZATION_BOILER_PLATE (shared_class::LeaveGameLobbyError)
SERIALIZATION_BOILER_PLATE (shared_class::WantToRelog)
SERIALIZATION_BOILER_PLATE (shared_class::RelogTo)
SERIALIZATION_BOILER_PLATE (shared_class::RelogToError)
SERIALIZATION_BOILER_PLATE (shared_class::RelogToSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::CreateAccountCancel)
SERIALIZATION_BOILER_PLATE (shared_class::LoginAccountCancel)
SERIALIZATION_BOILER_PLATE (shared_class::CreateGame)
SERIALIZATION_BOILER_PLATE (shared_class::StartGame)
SERIALIZATION_BOILER_PLATE (shared_class::CreateGameError)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAttack)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackError)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefend)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendError)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackPass)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackPassSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAttackPassError)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAssistPass)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAssistPassSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAssistPassError)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendPass)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendPassSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendPassError)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAskDefendWantToTakeCards)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAskDefendWantToTakeCardsAnswer)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAskDefendWantToTakeCardsAnswerSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::DurakAskDefendWantToTakeCardsAnswerError)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendWantsToTakeCardsFromTableDoYouWantToAddCards)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendWantsToTakeCardsFromTableDoYouWantToAddCardsAnswer)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendWantsToTakeCardsFromTableDoneAddingCards)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendWantsToTakeCardsFromTableDoneAddingCardsSuccess)
SERIALIZATION_BOILER_PLATE (shared_class::DurakDefendWantsToTakeCardsFromTableDoneAddingCardsError)
SERIALIZATION_BOILER_PLATE (shared_class::DurakGameOverWon)
SERIALIZATION_BOILER_PLATE (shared_class::DurakGameOverLose)
SERIALIZATION_BOILER_PLATE (shared_class::DurakGameOverDraw)
SERIALIZATION_BOILER_PLATE (durak::Type)
SERIALIZATION_BOILER_PLATE (durak::PlayerRole)
SERIALIZATION_BOILER_PLATE (durak::Card)
SERIALIZATION_BOILER_PLATE (durak::PlayerData)
SERIALIZATION_BOILER_PLATE (durak::GameData)

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
DurakDefendPass,
DurakDefendPassSuccess,
DurakDefendPassError,
durak::GameData,
DurakAskDefendWantToTakeCards,
DurakAskDefendWantToTakeCardsAnswer,
DurakAskDefendWantToTakeCardsAnswerSuccess,
DurakAskDefendWantToTakeCardsAnswerError,
DurakDefendWantsToTakeCardsFromTableDoYouWantToAddCards,
DurakDefendWantsToTakeCardsFromTableDoYouWantToAddCardsAnswer,
DurakDefendWantsToTakeCardsFromTableDoneAddingCards,
DurakDefendWantsToTakeCardsFromTableDoneAddingCardsSuccess,
DurakDefendWantsToTakeCardsFromTableDoneAddingCardsError,
DurakGameOverWon,
DurakGameOverLose,
DurakGameOverDraw
  >  const sharedClasses{};
}
// clang-format on
#endif /* A454B6F4_5E02_4669_955C_18F207EE36D6 */

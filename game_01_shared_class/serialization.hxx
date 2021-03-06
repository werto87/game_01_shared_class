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
#include <boost/json.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/range_c.hpp>
#include <cstddef>
#include <durak/game.hxx>
#include <iostream>
#include <map>
#include <sstream>
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
BOOST_FUSION_DEFINE_STRUCT ((shared_class), UsersInGameLobby, (std::string, name) (std::vector<shared_class::UserInGameLobby>, users) (size_t, maxUserSize) (durak::GameOption, durakGameOption))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), SetMaxUserSizeInCreateGameLobby, (size_t, maxUserSize))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), SetMaxUserSizeInCreateGameLobbyError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), MaxUserSizeInCreateGameLobby, (size_t, maxUserSize))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveGameLobby, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveGameLobbySuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveGameLobbyError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), WantToRelog, (std::string, accountName) (std::string, destination))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), RelogTo, (bool, wantsToRelog))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), RelogToCreateGameLobbySuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), RelogToGameSuccess, )
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
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakLeaveGame, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakLeaveGameError, (std::string, error))
typedef std::vector<std::pair<std::string, long long int>> UserTimeMilliseconds;
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakTimers, (UserTimeMilliseconds, runningTimeUserTimePointMilliseconds) (UserTimeMilliseconds, pausedTimeUserDurationMilliseconds))
namespace shared_class
{
enum struct Move
{
  AttackAssistPass,
  AttackAssistDoneAddingCards,
  AddCards,
  Defend,
  TakeCards,
  AnswerDefendWantsToTakeCardsYes,
  AnswerDefendWantsToTakeCardsNo
};
}
BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakAllowedMoves, (std::vector<shared_class::Move>, allowedMoves))

namespace shared_class
{
enum struct TimerType
{
  noTimer,
  resetTimeOnNewRound,
  addTimeOnNewRound
};
}
// TODO there is no support for std::chrono::seconds in confu_json
BOOST_FUSION_DEFINE_STRUCT ((shared_class), SetTimerOption, (shared_class::TimerType, timerType) (int, timeAtStartInSeconds) (int, timeForEachRoundInSeconds))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), SetTimerOptionError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), GameOptionError, (std::string, error))

BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinMatchMakingQueue, (bool, isRanked))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinMatchMakingQueueSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinMatchMakingQueueError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), AskIfUserWantsToJoinGame, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), AskIfUserWantsToJoinGameTimeOut, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), GameStartCanceled, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), GameStartCanceledRemovedFromQueue, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), WantsToJoinGame, (bool, answer))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), WantsToJoinGameError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveQuickGameQueue, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveQuickGameQueueSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveQuickGameQueueError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAsGuest, )
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAsGuestSuccess, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), RatingChanged, (size_t, oldRating) (size_t, newRating))

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
GameOptionError,
LeaveGameLobby,
LeaveGameLobbySuccess,
LeaveGameLobbyError,
WantToRelog,
RelogTo,
RelogToError,
RelogToCreateGameLobbySuccess,
RelogToGameSuccess,
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
DurakGameOverDraw,
DurakLeaveGame,
DurakLeaveGameError,
DurakTimers,
SetTimerOption,
SetTimerOptionError,
DurakAllowedMoves,
durak::GameOption,
AskIfUserWantsToJoinGame,
GameStartCanceled,
WantsToJoinGame,
WantsToJoinGameError,
AskIfUserWantsToJoinGameTimeOut,
GameStartCanceledRemovedFromQueue,
LeaveQuickGameQueue,
LeaveQuickGameQueueSuccess,
LeaveQuickGameQueueError,
LoginAsGuest,
LoginAsGuestSuccess,
JoinMatchMakingQueue,
JoinMatchMakingQueueSuccess,
JoinMatchMakingQueueError,
RatingChanged
  >  const sharedClasses{};
}
// clang-format on
#endif /* A454B6F4_5E02_4669_955C_18F207EE36D6 */

#ifndef A454B6F4_5E02_4669_955C_18F207EE36D6
#define A454B6F4_5E02_4669_955C_18F207EE36D6

#include "confu_boost/confuBoost.hxx"
#include <map>
#include <string>
#include <variant>

BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannel, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannelSuccess, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannelError, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccount, (std::string, accountName) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccountSuccess, (std::string, accountId) (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), CreateAccountError, (std::string, accountName) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAccount, (std::string, accountName) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAccountSuccess, (std::string, accountId) (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LoginAccountError, (std::string, accountId) (std::string, accountName) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), BroadCastMessage, (std::string, channel) (std::string, message))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), BroadCastMessageSuccess, (std::string, channel) (std::string, message))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), BroadCastMessageError, (std::string, channel) (std::string, password) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveChannel, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveChannelSuccess, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), LeaveChannelError, (std::string, channel) (std::string, error))

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

namespace shared_class
{
using sharedClassesTypes = std::variant<JoinChannel, JoinChannelSuccess, JoinChannelError, CreateAccount, CreateAccountSuccess, CreateAccountError, LoginAccount, LoginAccountSuccess, LoginAccountError, BroadCastMessage, BroadCastMessageSuccess, BroadCastMessageError, LeaveChannel, LeaveChannelSuccess, LeaveChannelError>;
static std::map<std::string, sharedClassesTypes> const sharedClassesLookup{ { "JoinChannel", JoinChannel{} }, { "JoinChannelSuccess", JoinChannelSuccess{} }, { "JoinChannelError", JoinChannelError{} }, { "CreateAccount", CreateAccount{} }, { "CreateAccountSuccess", CreateAccountSuccess{} }, { "CreateAccountError", CreateAccountError{} }, { "LoginAccount", LoginAccount{} }, { "LoginAccountSuccess", LoginAccountSuccess{} }, { "LoginAccountError", LoginAccountError{} }, { "BroadCastMessage", BroadCastMessage{} }, { "BroadCastMessageSuccess", BroadCastMessageSuccess{} }, { "BroadCastMessageError", BroadCastMessageError{} }, { "LeaveChannel", LeaveChannel{} }, { "LeaveChannelSuccess", LeaveChannelSuccess{} }, { "LeaveChannelError", LeaveChannelError{} } };
}
#endif /* A454B6F4_5E02_4669_955C_18F207EE36D6 */

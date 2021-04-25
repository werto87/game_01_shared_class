#ifndef A454B6F4_5E02_4669_955C_18F207EE36D6
#define A454B6F4_5E02_4669_955C_18F207EE36D6

#include "confu_boost/confuBoost.hxx"
#include <string>

BOOST_FUSION_DEFINE_STRUCT ((shared_class), JoinChannel, (std::string, channel))

BOOST_SERIALIZATION_BOILER_PLATE (shared_class::JoinChannel)

#endif /* A454B6F4_5E02_4669_955C_18F207EE36D6 */

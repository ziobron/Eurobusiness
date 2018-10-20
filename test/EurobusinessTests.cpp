#include <gtest/gtest.h>
#include "Eurobusiness.hpp"
#include "json.hpp"

struct EurobusinessTests : public ::testing::Test
{
};

TEST_F(EurobusinessTests, assertThatTrueIsTrue)
{
    ASSERT_TRUE(true);
}

TEST_F(EurobusinessTests, assertThatJSONParsingLibraryWorks)
{ 
    using json = nlohmann::json;

    json j;
    j["e"] = 2.71;

    ASSERT_EQ(j.dump(), "{\"e\":2.71}");
}

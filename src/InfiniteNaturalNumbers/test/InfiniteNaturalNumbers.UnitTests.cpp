#include "InfiniteNaturalNumbers/InfiniteNaturalNumbers.h"

#include "gtest/gtest.h"

#include <stdexcept>
#include <utility>

class InfiniteNaturalTest : public ::testing::Test
{
protected:
    static constexpr auto number       = 1234567;
    static constexpr auto other_number = 7654321;

    static constexpr auto big_number   = 999'999'999'999;
    static constexpr auto small_number = 1;
};

TEST_F(InfiniteNaturalTest, Constructor_WithoutParameters_Contains1)
{
    const auto number = MathXX::InfiniteNatural();

    EXPECT_EQ("1", number.ToString());
}

TEST_F(InfiniteNaturalTest, Constructor_Number_ContainsNumber)
{
    const auto natural_number = MathXX::InfiniteNatural(number);

    EXPECT_EQ(std::to_string(number), natural_number.ToString());
}

TEST_F(InfiniteNaturalTest, Constructor_Zero_ThrowsInvalidArgument)
{
    EXPECT_THROW({ const auto number = MathXX::InfiniteNatural(0); },
                 std::invalid_argument);
}

TEST_F(InfiniteNaturalTest, CopyConstructor_OtherObject_ContainsSameNumber)
{
    const auto expected_number = MathXX::InfiniteNatural(number);
    const auto actual_number   = MathXX::InfiniteNatural(expected_number);

    EXPECT_EQ(expected_number.ToString(), actual_number.ToString());
}

TEST_F(InfiniteNaturalTest, CopyConstructor_OtherObject_ObjectsDoNotShareValues)
{
    const auto expected_number = MathXX::InfiniteNatural(number);
    auto actual_number         = MathXX::InfiniteNatural(expected_number);

    actual_number = MathXX::InfiniteNatural(other_number);

    EXPECT_NE(expected_number.ToString(), actual_number.ToString());
}

TEST_F(InfiniteNaturalTest, MoveConstructor_OtherObject_ContainsSameNumber)
{
    auto number_to_move        = MathXX::InfiniteNatural(number);
    const auto expected_number = number_to_move.ToString();

    const auto actual_number =
        MathXX::InfiniteNatural(std::move(number_to_move));

    EXPECT_EQ(expected_number, actual_number.ToString());
}

TEST_F(InfiniteNaturalTest,
       CopyAssignmentOperator_OtherObject_ContainsSameNumber)
{
    const auto expected_number = MathXX::InfiniteNatural(number);
    auto actual_number         = MathXX::InfiniteNatural(other_number);

    ASSERT_NE(expected_number.ToString(), actual_number.ToString());

    actual_number = expected_number;

    EXPECT_EQ(expected_number.ToString(), actual_number.ToString());
}

// TEST_F(InfiniteNaturalTest,
// CopyAssignmentOperator_OtherObject_ObjectsDoNotShareValues)
//{
//    const auto expected_number = MathXX::InfiniteNatural(number);
//    auto actual_number         = MathXX::InfiniteNatural(other_number);
//
//    ASSERT_NE(expected_number.ToString(), actual_number.ToString());
//
//    actual_number = expected_number;
//
//    EXPECT_NE(expected_number.ToString(), actual_number.ToString());
//}

TEST_F(InfiniteNaturalTest,
       MoveAssignmentOperator_OtherObject_ContainsSameNumber)
{
    auto number_to_move        = MathXX::InfiniteNatural(number);
    const auto expected_number = number_to_move.ToString();

    auto actual_number = MathXX::InfiniteNatural(other_number);

    actual_number = std::move(number_to_move);

    EXPECT_EQ(expected_number, actual_number.ToString());
}

TEST_F(InfiniteNaturalTest, EqualsOperator_DifferentValueObject_False)
{
    const auto lhs = MathXX::InfiniteNatural(number);
    const auto rhs = MathXX::InfiniteNatural(other_number);

    EXPECT_FALSE(lhs == rhs);
}

TEST_F(InfiniteNaturalTest, EqualsOperator_SameValueObject_True)
{
    const auto lhs = MathXX::InfiniteNatural(number);
    const auto rhs = MathXX::InfiniteNatural(number);

    EXPECT_TRUE(lhs == rhs);
}

TEST_F(InfiniteNaturalTest, NotEqualsOperator_DifferentValueObject_True)
{
    const auto lhs = MathXX::InfiniteNatural(number);
    const auto rhs = MathXX::InfiniteNatural(other_number);

    EXPECT_TRUE(lhs != rhs);
}

TEST_F(InfiniteNaturalTest, NotEqualsOperator_SameValueObject_False)
{
    const auto lhs = MathXX::InfiniteNatural(number);
    const auto rhs = MathXX::InfiniteNatural(number);

    EXPECT_FALSE(lhs != rhs);
}

TEST_F(InfiniteNaturalTest, GreaterOperator_SameValueObject_False)
{
    const auto lhs = MathXX::InfiniteNatural(number);
    const auto rhs = MathXX::InfiniteNatural(number);

    EXPECT_FALSE(lhs > rhs);
}

TEST_F(InfiniteNaturalTest, GreaterOperator_GreaterValueObject_False)
{
    const auto lhs = MathXX::InfiniteNatural(small_number);
    const auto rhs = MathXX::InfiniteNatural(big_number);

    EXPECT_FALSE(lhs > rhs);
}

TEST_F(InfiniteNaturalTest, GreaterOperator_LessValueObject_True)
{
    const auto lhs = MathXX::InfiniteNatural(big_number);
    const auto rhs = MathXX::InfiniteNatural(small_number);

    EXPECT_TRUE(lhs > rhs);
}

TEST_F(InfiniteNaturalTest, GreaterEqualsOperator_SameValueObject_True)
{
    const auto lhs = MathXX::InfiniteNatural(number);
    const auto rhs = MathXX::InfiniteNatural(number);

    EXPECT_TRUE(lhs >= rhs);
}

TEST_F(InfiniteNaturalTest, GreaterEqualsOperator_GreaterValueObject_False)
{
    const auto lhs = MathXX::InfiniteNatural(small_number);
    const auto rhs = MathXX::InfiniteNatural(big_number);

    EXPECT_FALSE(lhs >= rhs);
}

TEST_F(InfiniteNaturalTest, GreaterEqualsOperator_LessValueObject_True)
{
    const auto lhs = MathXX::InfiniteNatural(big_number);
    const auto rhs = MathXX::InfiniteNatural(small_number);

    EXPECT_TRUE(lhs >= rhs);
}

TEST_F(InfiniteNaturalTest, LessOperator_SameValueObject_False)
{
    const auto lhs = MathXX::InfiniteNatural(number);
    const auto rhs = MathXX::InfiniteNatural(number);

    EXPECT_FALSE(lhs < rhs);
}

TEST_F(InfiniteNaturalTest, LessOperator_LessValueObject_False)
{
    const auto lhs = MathXX::InfiniteNatural(big_number);
    const auto rhs = MathXX::InfiniteNatural(small_number);

    EXPECT_FALSE(lhs < rhs);
}

TEST_F(InfiniteNaturalTest, LessOperator_GreaterValueObject_True)
{
    const auto lhs = MathXX::InfiniteNatural(small_number);
    const auto rhs = MathXX::InfiniteNatural(big_number);

    EXPECT_TRUE(lhs < rhs);
}

TEST_F(InfiniteNaturalTest, LessEqualsOperator_SameValueObject_True)
{
    const auto lhs = MathXX::InfiniteNatural(number);
    const auto rhs = MathXX::InfiniteNatural(number);

    EXPECT_TRUE(lhs <= rhs);
}

TEST_F(InfiniteNaturalTest, LessEqualsOperator_LessValueObject_False)
{
    const auto lhs = MathXX::InfiniteNatural(big_number);
    const auto rhs = MathXX::InfiniteNatural(small_number);

    EXPECT_FALSE(lhs <= rhs);
}

TEST_F(InfiniteNaturalTest, LessEqualsOperator_GreaterValueObject_True)
{
    const auto lhs = MathXX::InfiniteNatural(small_number);
    const auto rhs = MathXX::InfiniteNatural(big_number);

    EXPECT_TRUE(lhs <= rhs);
}

TEST_F(InfiniteNaturalTest, SetValue_InvalidString_FalseAndUnchanged)
{
    auto actual_number         = MathXX::InfiniteNatural(number);
    const auto expected_number = actual_number.ToString();

    ASSERT_FALSE(actual_number.SetValue(""));
    ASSERT_EQ(expected_number, actual_number.ToString());

    ASSERT_FALSE(actual_number.SetValue(" "));
    ASSERT_EQ(expected_number, actual_number.ToString());

    ASSERT_FALSE(actual_number.SetValue("a"));
    ASSERT_EQ(expected_number, actual_number.ToString());

    ASSERT_FALSE(actual_number.SetValue("1b"));
    ASSERT_EQ(expected_number, actual_number.ToString());

    ASSERT_FALSE(actual_number.SetValue("b1"));
    ASSERT_EQ(expected_number, actual_number.ToString());

    ASSERT_FALSE(actual_number.SetValue("1 1"));
    ASSERT_EQ(expected_number, actual_number.ToString());

    ASSERT_FALSE(actual_number.SetValue("-4"));
    ASSERT_EQ(expected_number, actual_number.ToString());

    ASSERT_FALSE(actual_number.SetValue("1.0"));
    ASSERT_EQ(expected_number, actual_number.ToString());

    ASSERT_FALSE(actual_number.SetValue("0"));
    ASSERT_EQ(expected_number, actual_number.ToString());
}

TEST_F(InfiniteNaturalTest, SetValue_NumberString_TrueNumberChangedToGiven)
{
    auto actual_number = MathXX::InfiniteNatural(number);

    ASSERT_TRUE(actual_number.SetValue("1"));
    ASSERT_EQ("1", actual_number.ToString());

    ASSERT_TRUE(actual_number.SetValue("116581618681618"));
    ASSERT_EQ("116581618681618", actual_number.ToString());

    ASSERT_TRUE(actual_number.SetValue("99999999999999999999"));
    ASSERT_EQ("99999999999999999999", actual_number.ToString());

    ASSERT_TRUE(actual_number.SetValue("999999999999999999999999999999999999999"
                                       "999999999999999999999"));
    ASSERT_EQ("999999999999999999999999999999999999999999999999999999999999",
              actual_number.ToString());
}

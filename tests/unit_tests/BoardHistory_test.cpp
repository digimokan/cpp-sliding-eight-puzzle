/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "BoardHistory.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"

TEST_CASE("is_in_history(Board), not_in_history(Board)") {

  BoardHistory history{};

  SUBCASE("is_in_history(Board)") {
    CHECK_FALSE(history.is_in_history(Board{"123405678"}));
  }

  SUBCASE("not_in_history(Board)") {
    CHECK_UNARY(history.not_in_history(Board{"123405678"}));
  }

}

TEST_CASE("add_to_history(Board)") {

  BoardHistory history{};
  Board B1{ "123405678" };
  Board B1_dup{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  Board BNULL{ "654832107" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNA) };

  SUBCASE("add_to_history(): single board") {
    history.add_to_history(B1, SNA);
    CHECK_UNARY(history.is_in_history(B1));
  }

  SUBCASE("add_to_history(): single duplicate board") {
    history.add_to_history(B1, SNA);
    CHECK_UNARY(history.is_in_history(B1_dup));
  }

  SUBCASE("add_to_history(): multiple boards") {
    history.add_to_history(B1, SNA);
    history.add_to_history(B2, SNB);
    history.add_to_history(B3, SNC);
    CHECK_UNARY(history.is_in_history(B1));
    CHECK_UNARY(history.is_in_history(B1_dup));
    CHECK_UNARY(history.is_in_history(B2));
    CHECK_UNARY(history.is_in_history(B3));
    CHECK_UNARY(history.not_in_history(BNULL));
  }

}

TEST_CASE("get_path_cost(Board)") {

  BoardHistory history{};
  Board B1{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  Board B3_dup{ "765483210" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNB) };

  SUBCASE("get_path_cost(): single board") {
    history.add_to_history(B1, SNA);
    CHECK_EQ(history.get_path_cost(B1), 0);
  }

  SUBCASE("get_path_cost(): multiple boards") {
    history.add_to_history(B1, SNA);
    history.add_to_history(B2, SNB);
    history.add_to_history(B3, SNC);
    CHECK_EQ(history.get_path_cost(B1), 0);
    CHECK_EQ(history.get_path_cost(B2), 1);
    CHECK_EQ(history.get_path_cost(B3), 4);
    CHECK_EQ(history.get_path_cost(B3_dup), 4);
  }

}


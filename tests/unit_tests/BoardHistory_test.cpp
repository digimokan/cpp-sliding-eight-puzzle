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

TEST_CASE("contains(Board), not_contains(Board)") {

  BoardHistory history{};

  SUBCASE("contains(Board)") {
    CHECK_FALSE(history.contains(Board{"123405678"}));
  }

  SUBCASE("not_contains(Board)") {
    CHECK_UNARY(history.not_contains(Board{"123405678"}));
  }

}

TEST_CASE("add(SearchNode)") {

  BoardHistory history{};
  Board B1{ "123405678" };
  Board B1_dup{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  Board BNULL{ "654832107" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNA) };

  SUBCASE("add(): single node") {
    history.add(SNA);
    CHECK_UNARY(history.contains(B1));
  }

  SUBCASE("add(): single duplicate nodes") {
    history.add(SNA);
    CHECK_UNARY(history.contains(B1_dup));
  }

  SUBCASE("add(): multiple nodes") {
    history.add(SNA);
    history.add(SNB);
    history.add(SNC);
    CHECK_UNARY(history.contains(B1));
    CHECK_UNARY(history.contains(B1_dup));
    CHECK_UNARY(history.contains(B2));
    CHECK_UNARY(history.contains(B3));
    CHECK_UNARY(history.not_contains(BNULL));
  }

}

TEST_CASE("remove(SearchNode)") {

  BoardHistory history{};
  Board BA{ "123405678" };
  Board BB{ "234105678" };
  Board BC{ "876543210" };
  Board BD{ "765483210" };
  Board BE{ "654832107" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(BA) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(BB) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(BC) };
  std::shared_ptr<SearchNode> SND{ std::make_shared<SearchNode>(BD) };
  std::shared_ptr<SearchNode> SNE{ std::make_shared<SearchNode>(BE) };

  SUBCASE("remove(): single node") {
    history.add(SNA);
    CHECK_UNARY(history.contains(BA));
    history.remove(SNA);
    CHECK_FALSE(history.contains(BA));
  }

  SUBCASE("remove(): three nodes") {
    history.add(SNA);
    CHECK_UNARY(history.contains(BA));
    history.add(SNB);
    CHECK_UNARY(history.contains(BB));
    history.add(SNC);
    CHECK_UNARY(history.contains(BC));
    history.remove(SNA);
    CHECK_FALSE(history.contains(BA));
    history.remove(SNB);
    CHECK_FALSE(history.contains(BB));
    history.remove(SNC);
    CHECK_FALSE(history.contains(BC));
  }

  SUBCASE("add() and remove() same node repeatedly") {
    history.add(SNA);
    CHECK_UNARY(history.contains(BA));
    history.remove(SNA);
    CHECK_FALSE(history.contains(BA));
    history.add(SNA);
    CHECK_UNARY(history.contains(BA));
    history.remove(SNA);
    CHECK_FALSE(history.contains(BA));
    history.add(SNA);
    CHECK_UNARY(history.contains(BA));
    history.remove(SNA);
    CHECK_FALSE(history.contains(BA));
  }

}

TEST_CASE("size()") {

  BoardHistory history{};
  Board B1{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNA) };

  SUBCASE("empty history") {
    CHECK_EQ(history.get_size(), 0);
  }

  SUBCASE("history of 1") {
    history.add(SNA);
    CHECK_EQ(history.get_size(), 1);
  }

  SUBCASE("history of 2") {
    history.add(SNA);
    history.add(SNB);
    CHECK_EQ(history.get_size(), 2);
  }

  SUBCASE("history of 3") {
    history.add(SNA);
    history.add(SNB);
    history.add(SNC);
    CHECK_EQ(history.get_size(), 3);
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
    history.add(SNA);
    CHECK_EQ(history.get_path_cost(B1), 0);
  }

  SUBCASE("get_path_cost(): multiple boards") {
    history.add(SNA);
    history.add(SNB);
    history.add(SNC);
    CHECK_EQ(history.get_path_cost(B1), 0);
    CHECK_EQ(history.get_path_cost(B2), 1);
    CHECK_EQ(history.get_path_cost(B3), 4);
    CHECK_EQ(history.get_path_cost(B3_dup), 4);
  }

}


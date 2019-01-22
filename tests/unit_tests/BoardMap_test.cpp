/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "BoardMap.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("contains(Board), not_contains(Board)") {

  BoardMap map{};
  Board B1{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNA_dup{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNB_dup{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNA) };
  std::shared_ptr<SearchNode> SNC_dup{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNA) };

  SUBCASE("contains(Board)") {
    CHECK_FALSE(map.contains(Board{"123405678"}));
  }

  SUBCASE("not_contains(Board)") {
    CHECK_UNARY(map.not_contains(Board{"123405678"}));
  }

  SUBCASE("nodes with duplicate boards") {
    map.add(SNA);
    map.add(SNB);
    map.add(SNC);
    CHECK_UNARY(map.contains(SNA_dup->get_board()));
    CHECK_UNARY(map.contains(SNB_dup->get_board()));
    CHECK_UNARY(map.contains(SNC_dup->get_board()));
  }

}

TEST_CASE("add(SearchNode)") {

  BoardMap map{};
  Board B1{ "123405678" };
  Board B1_dup{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  Board BNULL{ "654832107" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNA) };

  SUBCASE("add(): single node") {
    map.add(SNA);
    CHECK_UNARY(map.contains(B1));
  }

  SUBCASE("add(): single duplicate nodes") {
    map.add(SNA);
    CHECK_UNARY(map.contains(B1_dup));
  }

  SUBCASE("add(): multiple nodes") {
    map.add(SNA);
    map.add(SNB);
    map.add(SNC);
    CHECK_UNARY(map.contains(B1));
    CHECK_UNARY(map.contains(B1_dup));
    CHECK_UNARY(map.contains(B2));
    CHECK_UNARY(map.contains(B3));
    CHECK_UNARY(map.not_contains(BNULL));
  }

}

TEST_CASE("get_node(Board)") {

  BoardMap map{};
  Board B1{ "123405678" };
  Board B1_dup{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNA) };

  SUBCASE("empty BoardMap") {
    CHECK_EQ(map.get_node(B1), std::nullopt);
  }

  SUBCASE("one add") {
    map.add(SNA);
    CHECK_EQ(map.get_node(B1), SNA);
  }

  SUBCASE("one add/remove of same node") {
    map.add(SNA);
    map.remove(SNA);
    CHECK_EQ(map.get_node(B1), std::nullopt);
  }

  SUBCASE("three adds") {
    map.add(SNA);
    map.add(SNB);
    map.add(SNC);
    CHECK_EQ(map.get_node(B1), SNA);
    CHECK_EQ(map.get_node(B2), SNB);
    CHECK_EQ(map.get_node(B3), SNC);
  }

  SUBCASE("three adds/removes of same node") {
    map.add(SNA);
    map.add(SNB);
    map.add(SNC);
    map.remove(SNA);
    map.remove(SNB);
    map.remove(SNC);
    CHECK_EQ(map.get_node(B1), std::nullopt);
    CHECK_EQ(map.get_node(B2), std::nullopt);
    CHECK_EQ(map.get_node(B3), std::nullopt);
  }

  SUBCASE("repeated add/remove of same node") {
    map.add(SNA);
    CHECK_EQ(map.get_node(B1), SNA);
    map.remove(SNA);
    CHECK_EQ(map.get_node(B1), std::nullopt);
    map.add(SNA);
    CHECK_EQ(map.get_node(B1), SNA);
    map.remove(SNA);
    CHECK_EQ(map.get_node(B1), std::nullopt);
    map.add(SNA);
    CHECK_EQ(map.get_node(B1), SNA);
    map.remove(SNA);
    CHECK_EQ(map.get_node(B1), std::nullopt);
  }

  SUBCASE("node with duplicate board") {
    map.add(SNA);
    CHECK_EQ(map.get_node(B1_dup), SNA);
  }

}

TEST_CASE("remove(SearchNode)") {

  BoardMap map{};
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
    map.add(SNA);
    CHECK_UNARY(map.contains(BA));
    map.remove(SNA);
    CHECK_FALSE(map.contains(BA));
  }

  SUBCASE("remove(): three nodes") {
    map.add(SNA);
    CHECK_UNARY(map.contains(BA));
    map.add(SNB);
    CHECK_UNARY(map.contains(BB));
    map.add(SNC);
    CHECK_UNARY(map.contains(BC));
    map.remove(SNA);
    CHECK_FALSE(map.contains(BA));
    map.remove(SNB);
    CHECK_FALSE(map.contains(BB));
    map.remove(SNC);
    CHECK_FALSE(map.contains(BC));
  }

  SUBCASE("add() and remove() same node repeatedly") {
    map.add(SNA);
    CHECK_UNARY(map.contains(BA));
    map.remove(SNA);
    CHECK_FALSE(map.contains(BA));
    map.add(SNA);
    CHECK_UNARY(map.contains(BA));
    map.remove(SNA);
    CHECK_FALSE(map.contains(BA));
    map.add(SNA);
    CHECK_UNARY(map.contains(BA));
    map.remove(SNA);
    CHECK_FALSE(map.contains(BA));
  }

}

TEST_CASE("size()") {

  BoardMap map{};
  Board B1{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNA) };

  SUBCASE("empty map") {
    CHECK_EQ(map.get_size(), 0);
  }

  SUBCASE("map of 1") {
    map.add(SNA);
    CHECK_EQ(map.get_size(), 1);
  }

  SUBCASE("map of 2") {
    map.add(SNA);
    map.add(SNB);
    CHECK_EQ(map.get_size(), 2);
  }

  SUBCASE("map of 3") {
    map.add(SNA);
    map.add(SNB);
    map.add(SNC);
    CHECK_EQ(map.get_size(), 3);
  }

}

TEST_CASE("get_path_cost(Board)") {

  BoardMap map{};
  Board B1{ "123405678" };
  Board B2{ "876543210" };
  Board B3{ "765483210" };
  Board B3_dup{ "765483210" };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(B1) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{B2, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{B3, MoveDir::DOWN, 3}, SNB) };

  SUBCASE("get_path_cost(): single board") {
    map.add(SNA);
    CHECK_EQ(map.get_path_cost(B1), 0);
  }

  SUBCASE("get_path_cost(): multiple boards") {
    map.add(SNA);
    map.add(SNB);
    map.add(SNC);
    CHECK_EQ(map.get_path_cost(B1), 0);
    CHECK_EQ(map.get_path_cost(B2), 1);
    CHECK_EQ(map.get_path_cost(B3), 4);
    CHECK_EQ(map.get_path_cost(B3_dup), 4);
  }

}


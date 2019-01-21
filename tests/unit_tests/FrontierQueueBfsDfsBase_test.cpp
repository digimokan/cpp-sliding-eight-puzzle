/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cassert>
#include <list>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "FrontierQueueBfsDfsBase.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* MOCKS
*******************************************************************************/

class BDBQMock : public FrontierQueueBfsDfsBase {
private:
  void push_logic (std::shared_ptr<SearchNode> node) override { this->fq.push_back(node); }
  std::shared_ptr<SearchNode> pop_logic () override {
    assert(this->not_empty());
    auto node{ this->fq.back() };
    this->fq.pop_back();
    return node;
  }
};

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("is_empty()") {

  BDBQMock q{};
  std::shared_ptr<SearchNode> A{ std::make_shared<SearchNode>(Board{"012345678"}) };

  SUBCASE("empty queue") {
    CHECK_UNARY(q.is_empty());
  }

  SUBCASE("one push") {
    q.push(A);
    CHECK_FALSE(q.is_empty());
  }

}

TEST_CASE("contains()") {

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  Board BD{ Board{"134862750"} };
  Board BE{ Board{"104832765"} };
  Board BF{ Board{"134082765"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  auto SNA_dup{ std::make_shared<SearchNode>(BA) };
  auto SNB{ std::make_shared<SearchNode>(BB) };
  auto SNB_dup{ std::make_shared<SearchNode>(BB) };
  auto SNC{ std::make_shared<SearchNode>(BC) };
  auto SNC_dup{ std::make_shared<SearchNode>(BC) };
  auto SND{ std::make_shared<SearchNode>(BD) };
  auto SNE{ std::make_shared<SearchNode>(BE) };
  auto SNF{ std::make_shared<SearchNode>(BF) };
  BDBQMock q{};

  SUBCASE("empty queue") {
    CHECK_FALSE(q.contains(BA));
    CHECK_UNARY(q.not_contains(BA));
  }

  SUBCASE("one push") {
    q.push(SNA);
    CHECK_UNARY(q.contains(BA));
  }

  SUBCASE("one push, one pop") {
    q.push(SNA);
    q.pop();
    CHECK_FALSE(q.contains(BA));
  }

  SUBCASE("three pushes") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    CHECK_UNARY(q.contains(BA));
    CHECK_UNARY(q.contains(BB));
    CHECK_UNARY(q.contains(BC));
  }

  SUBCASE("three pushes, three pops") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    q.pop();
    q.pop();
    q.pop();
    CHECK_FALSE(q.contains(BA));
    CHECK_FALSE(q.contains(BB));
    CHECK_FALSE(q.contains(BC));
  }

  SUBCASE("repeated push/pop of same element") {
    q.push(SNA);
    CHECK_UNARY(q.contains(BA));
    q.pop();
    CHECK_FALSE(q.contains(BA));
    q.push(SNA);
    CHECK_UNARY(q.contains(BA));
    q.pop();
    CHECK_FALSE(q.contains(BA));
    q.push(SNA);
    CHECK_UNARY(q.contains(BA));
    q.pop();
    CHECK_FALSE(q.contains(BA));
  }

  SUBCASE("nodes with duplicate boards") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    CHECK_UNARY(q.contains(SNA_dup->get_board()));
    CHECK_UNARY(q.contains(SNB_dup->get_board()));
    CHECK_UNARY(q.contains(SNC_dup->get_board()));
  }

}

TEST_CASE("get_node()") {

  Board BA{ Board{"134862705"} };
  Board BB{ Board{"134802765"} };
  Board BC{ Board{"134862075"} };
  Board BD{ Board{"134862750"} };
  Board BE{ Board{"104832765"} };
  Board BF{ Board{"134082765"} };
  auto SNA{ std::make_shared<SearchNode>(BA) };
  auto SNA_dup{ std::make_shared<SearchNode>(BA) };
  auto SNB{ std::make_shared<SearchNode>(BB) };
  auto SNB_dup{ std::make_shared<SearchNode>(BB) };
  auto SNC{ std::make_shared<SearchNode>(BC) };
  auto SNC_dup{ std::make_shared<SearchNode>(BC) };
  auto SND{ std::make_shared<SearchNode>(BD) };
  auto SNE{ std::make_shared<SearchNode>(BE) };
  auto SNF{ std::make_shared<SearchNode>(BF) };
  BDBQMock q{};

  SUBCASE("empty queue") {
    CHECK_EQ(q.get_node(BA), std::nullopt);
  }

  SUBCASE("one push") {
    q.push(SNA);
    CHECK_EQ(q.get_node(BA), SNA);
  }

  SUBCASE("one push, one pop") {
    q.push(SNA);
    q.pop();
    CHECK_EQ(q.get_node(BA), std::nullopt);
  }

  SUBCASE("three pushes") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    CHECK_EQ(q.get_node(BA), SNA);
    CHECK_EQ(q.get_node(BB), SNB);
    CHECK_EQ(q.get_node(BC), SNC);
  }

  SUBCASE("three pushes, three pops") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    q.pop();
    q.pop();
    q.pop();
    CHECK_EQ(q.get_node(BA), std::nullopt);
    CHECK_EQ(q.get_node(BB), std::nullopt);
    CHECK_EQ(q.get_node(BC), std::nullopt);
  }

  SUBCASE("repeated push/pop of same element") {
    q.push(SNA);
    CHECK_EQ(q.get_node(BA), SNA);
    q.pop();
    CHECK_EQ(q.get_node(BA), std::nullopt);
    q.push(SNA);
    CHECK_EQ(q.get_node(BA), SNA);
    q.pop();
    CHECK_EQ(q.get_node(BA), std::nullopt);
    q.push(SNA);
    CHECK_EQ(q.get_node(BA), SNA);
    q.pop();
    CHECK_EQ(q.get_node(BA), std::nullopt);
  }

  SUBCASE("nodes with duplicate boards") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    CHECK_EQ(q.get_node(SNA_dup->get_board()), SNA);
    CHECK_EQ(q.get_node(SNB_dup->get_board()), SNB);
    CHECK_EQ(q.get_node(SNC_dup->get_board()), SNC);
  }

}

TEST_CASE("get_current_queue_size()") {

  BDBQMock q{};
  std::shared_ptr<SearchNode> A{ std::make_shared<SearchNode>(Board{"012345678"}) };
  std::shared_ptr<SearchNode> B{ std::make_shared<SearchNode>(Move{Board{"102345678"}, MoveDir::RIGHT, 1}, A) };
  std::shared_ptr<SearchNode> C{ std::make_shared<SearchNode>(Move{Board{"312045678"}, MoveDir::DOWN, 3}, A) };
  std::shared_ptr<SearchNode> D{ std::make_shared<SearchNode>(Move{Board{"312405678"}, MoveDir::RIGHT, 4}, C) };
  std::shared_ptr<SearchNode> E{ std::make_shared<SearchNode>(Move{Board{"312645078"}, MoveDir::DOWN, 6}, C) };
  std::shared_ptr<SearchNode> F{ std::make_shared<SearchNode>(Move{Board{"302415678"}, MoveDir::UP, 1}, D) };

  SUBCASE("empty queue") {
    CHECK_EQ(q.get_current_queue_size(), 0);
  }

  SUBCASE("one push") {
    q.push(A);
    CHECK_EQ(q.get_current_queue_size(), 1);
  }

  SUBCASE("one push, one pop") {
    q.push(A);
    q.pop();
    CHECK_EQ(q.get_current_queue_size(), 0);
  }

  SUBCASE("4 pushes, 3 pops, 1 push, 1 pop") {
    q.push(A);
    q.push(B);
    q.push(C);
    q.push(D);
    q.pop();
    q.pop();
    q.pop();
    q.push(E);
    q.pop();
    CHECK_EQ(q.get_current_queue_size(), 1);
  }

}


/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "FrontierQueueBFS.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("is_empty()") {

  FrontierQueueBFS q{};
  std::shared_ptr<SearchNode> A{ std::make_shared<SearchNode>(Board{"012345678"}) };

  SUBCASE("empty queue") {
    CHECK_UNARY(q.is_empty());
  }

  SUBCASE("one push") {
    q.push(A);
    CHECK_FALSE(q.is_empty());
  }

}

TEST_CASE("get_current_queue_size()") {

  FrontierQueueBFS q{};
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

TEST_CASE("push(), pop()") {

  FrontierQueueBFS q{};
  Board BA{ Board{"012345678"} };
  Board BB{ Board{"102345678"} };
  Board BC{ Board{"312045678"} };
  Board BD{ Board{"312405678"} };
  Board BE{ Board{"312645078"} };
  std::shared_ptr<SearchNode> SNA{ std::make_shared<SearchNode>(BA) };
  std::shared_ptr<SearchNode> SNB{ std::make_shared<SearchNode>(Move{BB, MoveDir::RIGHT, 1}, SNA) };
  std::shared_ptr<SearchNode> SNC{ std::make_shared<SearchNode>(Move{BC, MoveDir::DOWN, 3}, SNA) };
  std::shared_ptr<SearchNode> SND{ std::make_shared<SearchNode>(Move{BD, MoveDir::RIGHT, 4}, SNC) };
  std::shared_ptr<SearchNode> SNE{ std::make_shared<SearchNode>(Move{BE, MoveDir::DOWN, 6}, SNC) };

  SUBCASE("4 pushes, 1 pop") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    q.push(SND);
    auto sn{ q.pop() };
    CHECK_UNARY(sn->get_board() == BA);
  }

  SUBCASE("4 pushes, 2 pops") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    q.push(SND);
    q.pop();
    auto sn{ q.pop() };
    CHECK_UNARY(sn->get_board() == BB);
  }

  SUBCASE("4 pushes, 3 pops") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    q.push(SND);
    q.pop();
    q.pop();
    auto sn{ q.pop() };
    CHECK_UNARY(sn->get_board() == BC);
  }

  SUBCASE("4 pushes, 3 pops, 1 push, 1 pop") {
    q.push(SNA);
    q.push(SNB);
    q.push(SNC);
    q.push(SND);
    q.pop();
    q.pop();
    q.pop();
    q.push(SNE);
    auto sn{ q.pop() };
    CHECK_UNARY(sn->get_board() == BD);
  }

}

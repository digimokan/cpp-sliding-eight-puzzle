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


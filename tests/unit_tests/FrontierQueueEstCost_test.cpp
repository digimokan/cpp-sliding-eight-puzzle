/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "EstGoalCostUniform.hpp"
#include "FrontierQueueEstCost.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("push(), pop()") {

  FrontierQueueEstCost<EstGoalCostUniform> q{};
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

  SUBCASE("push SND, SNC, SNA, SNE, SNB") {
    q.push(SND);
    q.push(SNC);
    q.push(SNA);
    q.push(SNE);
    q.push(SNB);
    CHECK_EQ(q.pop(), SNA);
    CHECK_EQ(q.pop(), SNB);
    CHECK_EQ(q.pop(), SNC);
    CHECK_EQ(q.pop(), SND);
    CHECK_EQ(q.pop(), SNE);
  }

}


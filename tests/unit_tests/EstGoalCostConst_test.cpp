/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostConst.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("get const cost to goal") {

  EstGoalCostConst est{};

  SUBCASE("get_est_goal_cost()") {
    CHECK_EQ(est.get_est_goal_cost(std::make_shared<SearchNode>(Board{ "012345678" })), 1);
    CHECK_EQ(est.get_est_goal_cost(std::make_shared<SearchNode>(Board{ "123405678" })), 1);
    CHECK_EQ(est.get_est_goal_cost(std::make_shared<SearchNode>(Board{ "876543210" })), 1);
  }

}


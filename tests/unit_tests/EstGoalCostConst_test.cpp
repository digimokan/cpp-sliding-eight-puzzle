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

TEST_CASE("get_est_goal_cost()") {

  EstGoalCostConst est{};

  SUBCASE("diff boards all return cost of 1") {
    CHECK_EQ(est.get_est_goal_cost(std::make_shared<SearchNode>(Board{ "012345678" })), 0);
    CHECK_EQ(est.get_est_goal_cost(std::make_shared<SearchNode>(Board{ "123405678" })), 0);
    CHECK_EQ(est.get_est_goal_cost(std::make_shared<SearchNode>(Board{ "876543210" })), 0);
  }

}


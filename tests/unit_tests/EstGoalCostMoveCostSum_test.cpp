/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostMoveCostSum.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("get_est_goal_cost()") {

  std::shared_ptr<SearchNode> A{ std::make_shared<SearchNode>(Board{"123804765"}) };
  std::shared_ptr<SearchNode> B{ std::make_shared<SearchNode>(Board{"023814765"}) };
  std::shared_ptr<SearchNode> C{ std::make_shared<SearchNode>(Board{"123480765"}) };
  std::shared_ptr<SearchNode> D{ std::make_shared<SearchNode>(Board{"123485760"}) };
  std::shared_ptr<SearchNode> E{ std::make_shared<SearchNode>(Board{"123485706"}) };
  std::shared_ptr<SearchNode> F{ std::make_shared<SearchNode>(Board{"123487506"}) };
  EstGoalCostMoveCostSum est{};

  SUBCASE("A est goal cost") {
    CHECK_EQ(est.get_est_goal_cost(A), 20);
  }

  SUBCASE("B est goal cost") {
    CHECK_EQ(est.get_est_goal_cost(B), 10);
  }

  SUBCASE("C est goal cost") {
    CHECK_EQ(est.get_est_goal_cost(C), 16);
  }

  SUBCASE("D est goal cost") {
    CHECK_EQ(est.get_est_goal_cost(D), 11);
  }

  SUBCASE("E est goal cost") {
    CHECK_EQ(est.get_est_goal_cost(E), 21);
  }

  SUBCASE("F est goal cost") {
    CHECK_EQ(est.get_est_goal_cost(F), 19);
  }

}


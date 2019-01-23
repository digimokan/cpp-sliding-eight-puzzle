/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostMisplSq.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("get_est_goal_cost()") {

  const Board goal{ "123804765" };
  std::shared_ptr<SearchNode> mispl_0{ std::make_shared<SearchNode>(Board{"123804765"}) };
  std::shared_ptr<SearchNode> mispl_2{ std::make_shared<SearchNode>(Board{"023814765"}) };
  std::shared_ptr<SearchNode> mispl_3{ std::make_shared<SearchNode>(Board{"123480765"}) };
  std::shared_ptr<SearchNode> mispl_4{ std::make_shared<SearchNode>(Board{"123485760"}) };
  std::shared_ptr<SearchNode> mispl_5{ std::make_shared<SearchNode>(Board{"123485706"}) };
  std::shared_ptr<SearchNode> mispl_6{ std::make_shared<SearchNode>(Board{"123487506"}) };
  std::shared_ptr<SearchNode> mispl_7{ std::make_shared<SearchNode>(Board{"124387506"}) };
  std::shared_ptr<SearchNode> mispl_8{ std::make_shared<SearchNode>(Board{"567408321"}) };
  std::shared_ptr<SearchNode> mispl_9{ std::make_shared<SearchNode>(Board{"512380476"}) };
  EstGoalCostMisplSq est{ goal };

  SUBCASE("misplaced squares: 0") {
    CHECK_EQ(est.get_est_goal_cost(mispl_0), 0);
  }

  SUBCASE("misplaced squares: 2") {
    CHECK_EQ(est.get_est_goal_cost(mispl_2), 2);
  }

  SUBCASE("misplaced squares: 3") {
    CHECK_EQ(est.get_est_goal_cost(mispl_3), 3);
  }

  SUBCASE("misplaced squares: 4") {
    CHECK_EQ(est.get_est_goal_cost(mispl_4), 4);
  }

  SUBCASE("misplaced squares: 5") {
    CHECK_EQ(est.get_est_goal_cost(mispl_5), 5);
  }

  SUBCASE("misplaced squares: 6") {
    CHECK_EQ(est.get_est_goal_cost(mispl_6), 6);
  }

  SUBCASE("misplaced squares: 7") {
    CHECK_EQ(est.get_est_goal_cost(mispl_7), 7);
  }

  SUBCASE("misplaced squares: 8") {
    CHECK_EQ(est.get_est_goal_cost(mispl_8), 8);
  }

  SUBCASE("misplaced squares: 9") {
    CHECK_EQ(est.get_est_goal_cost(mispl_9), 9);
  }

}


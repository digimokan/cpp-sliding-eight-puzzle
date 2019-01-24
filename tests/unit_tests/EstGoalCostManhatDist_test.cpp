/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostManhatDist.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("get_est_goal_cost()") {

  const Board goal{ "123804765" };
  std::shared_ptr<SearchNode> board_eq{ std::make_shared<SearchNode>(Board{"123804765"}) };
  std::shared_ptr<SearchNode> same_row_swap{ std::make_shared<SearchNode>(Board{"213804765"}) };
  std::shared_ptr<SearchNode> diag_adj_swap{ std::make_shared<SearchNode>(Board{"183204765"}) };
  std::shared_ptr<SearchNode> three_opposite_mixed{ std::make_shared<SearchNode>(Board{"152804763"}) };
  std::shared_ptr<SearchNode> top_bottom_row_swap{ std::make_shared<SearchNode>(Board{"765804123"}) };
  std::shared_ptr<SearchNode> corners_reversed{ std::make_shared<SearchNode>(Board{"527804361"}) };
  std::shared_ptr<SearchNode> many{ std::make_shared<SearchNode>(Board{"548610732"}) };
  EstGoalCostManhatDist est{ goal };

  SUBCASE("boards equal") {
    CHECK_EQ(est.get_est_goal_cost(board_eq), 0);
  }

  SUBCASE("two same-row squares swapped") {
    CHECK_EQ(est.get_est_goal_cost(same_row_swap), 2);
  }

  SUBCASE("two diagonal-adjacent squares swapped") {
    CHECK_EQ(est.get_est_goal_cost(diag_adj_swap), 4);
  }

  SUBCASE("three opposite squares mixed") {
    CHECK_EQ(est.get_est_goal_cost(three_opposite_mixed), 6);
  }

  SUBCASE("top/bottom rows swapped") {
    CHECK_EQ(est.get_est_goal_cost(top_bottom_row_swap), 12);
  }

  SUBCASE("corners reversed") {
    CHECK_EQ(est.get_est_goal_cost(corners_reversed), 16);
  }

  SUBCASE("many squares misplaced") {
    CHECK_EQ(est.get_est_goal_cost(many), 20);
  }

}


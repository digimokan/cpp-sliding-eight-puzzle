/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostAstarOne.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* TEST CASES
*******************************************************************************/

TEST_CASE("get_est_goal_cost()") {

/*******************************************************************************
        A
      / |
     B  C
       / \
      D  E
      |
      F
*******************************************************************************/

  const Board goal_board{ "123804765" };
  std::shared_ptr<SearchNode> A{ std::make_shared<SearchNode>(Board{"012345678"}) };
  std::shared_ptr<SearchNode> B{ std::make_shared<SearchNode>(Move{Board{"102345678"}, MoveDir::RIGHT, 1}, A) };
  std::shared_ptr<SearchNode> C{ std::make_shared<SearchNode>(Move{Board{"312045678"}, MoveDir::DOWN, 3}, A) };
  std::shared_ptr<SearchNode> D{ std::make_shared<SearchNode>(Move{Board{"312405678"}, MoveDir::RIGHT, 4}, C) };
  std::shared_ptr<SearchNode> E{ std::make_shared<SearchNode>(Move{Board{"312645078"}, MoveDir::DOWN, 6}, C) };
  std::shared_ptr<SearchNode> F{ std::make_shared<SearchNode>(Move{Board{"302415678"}, MoveDir::UP, 1}, D) };
  std::shared_ptr<SearchNode> goal_node{ std::make_shared<SearchNode>(goal_board) };
  A->add_child(B);
  A->add_child(C);
  C->add_child(D);
  C->add_child(E);
  D->add_child(F);
  EstGoalCostAstarOne est{ goal_board };

  SUBCASE("A misplaced squares") {
    CHECK_EQ(est.get_est_goal_cost(A), 9);
  }

  SUBCASE("B misplaced squares") {
    CHECK_EQ(est.get_est_goal_cost(B), 9);
  }

  SUBCASE("C misplaced squares") {
    CHECK_EQ(est.get_est_goal_cost(C), 12);
  }

  SUBCASE("D misplaced squares") {
    CHECK_EQ(est.get_est_goal_cost(D), 15);
  }

  SUBCASE("E misplaced squares") {
    CHECK_EQ(est.get_est_goal_cost(E), 18);
  }

  SUBCASE("F misplaced squares") {
    CHECK_EQ(est.get_est_goal_cost(F), 17);
  }

  SUBCASE("goal misplaced squares (should be 0)") {
    CHECK_EQ(est.get_est_goal_cost(goal_node), 0);
  }

}


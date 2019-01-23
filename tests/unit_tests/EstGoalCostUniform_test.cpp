/*******************************************************************************
* DOCTEST CONFIG
*******************************************************************************/

#include "doctest.h"

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostUniform.hpp"
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

  std::shared_ptr<SearchNode> A{ std::make_shared<SearchNode>(Board{"012345678"}) };
  std::shared_ptr<SearchNode> B{ std::make_shared<SearchNode>(Move{Board{"102345678"}, MoveDir::RIGHT, 1}, A) };
  std::shared_ptr<SearchNode> C{ std::make_shared<SearchNode>(Move{Board{"312045678"}, MoveDir::DOWN, 3}, A) };
  std::shared_ptr<SearchNode> D{ std::make_shared<SearchNode>(Move{Board{"312405678"}, MoveDir::RIGHT, 4}, C) };
  std::shared_ptr<SearchNode> E{ std::make_shared<SearchNode>(Move{Board{"312645078"}, MoveDir::DOWN, 6}, C) };
  std::shared_ptr<SearchNode> F{ std::make_shared<SearchNode>(Move{Board{"302415678"}, MoveDir::UP, 1}, D) };
  A->add_child(B);
  A->add_child(C);
  C->add_child(D);
  C->add_child(E);
  D->add_child(F);
  EstGoalCostUniform est{};

  SUBCASE("root node") {
    CHECK_EQ(est.get_est_goal_cost(A), 0);
  }

  SUBCASE("leaf node, depth 1") {
    CHECK_EQ(est.get_est_goal_cost(B), 1);
  }

  SUBCASE("middle node, depth 2") {
    CHECK_EQ(est.get_est_goal_cost(D), 7);
  }

  SUBCASE("leaf node, depth 3") {
    CHECK_EQ(est.get_est_goal_cost(F), 8);
  }

}


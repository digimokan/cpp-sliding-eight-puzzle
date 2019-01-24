/*******************************************************************************
module:   EstGoalCostAstarThree
author:   digimokan
date:     24 JAN 2019
purpose:  A*3 informed strategy, f(n) = combination of these three strategies:
            1. g(n) = uniform cost
            2. h(n) = sum of board's manhattan distances
            3. h(n) = sum of costs of board's possible moves
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostAstarThree.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

EstGoalCostAstarThree::EstGoalCostAstarThree (const Board& goal_board)
  : est_cost_uniform{},
    est_cost_manhat_dist{goal_board},
    est_cost_move_cost_sum{}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int EstGoalCostAstarThree::get_est_goal_cost (std::shared_ptr<SearchNode> node) const {
  return (
    this->est_cost_uniform.get_est_goal_cost(node) +
    this->est_cost_manhat_dist.get_est_goal_cost(node) +
    this->est_cost_move_cost_sum.get_est_goal_cost(node)
  );
}


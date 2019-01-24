/*******************************************************************************
module:   EstGoalCostAstarTwo
author:   digimokan
date:     24 JAN 2019
purpose:  A*2 informed strategy, f(n) = combination of these two strategies:
            1. g(n) = uniform cost
            2. h(n) = sum of board's manhattan distances
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostAstarTwo.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

EstGoalCostAstarTwo::EstGoalCostAstarTwo (const Board& goal_board)
  : est_cost_uniform{},
    est_cost_manhat_dist{goal_board}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int EstGoalCostAstarTwo::get_est_goal_cost (std::shared_ptr<SearchNode> node) const {
  return (
    this->est_cost_uniform.get_est_goal_cost(node) +
    this->est_cost_manhat_dist.get_est_goal_cost(node)
  );
}


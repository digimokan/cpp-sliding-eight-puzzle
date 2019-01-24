/*******************************************************************************
module:   EstGoalCostAstarOne
author:   digimokan
date:     24 JAN 2019
purpose:  A*1 informed strategy, f(n) = combination of these two strategies:
            1. g(n) = uniform cost
            2. h(n) = number of misplaced tiles
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostAstarOne.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

EstGoalCostAstarOne::EstGoalCostAstarOne (const Board& goal_board)
  : est_cost_uniform{},
    est_cost_mispl_sq{goal_board}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int EstGoalCostAstarOne::get_est_goal_cost (std::shared_ptr<SearchNode> node) const {
  return (
    this->est_cost_uniform.get_est_goal_cost(node) +
    this->est_cost_mispl_sq.get_est_goal_cost(node)
  );
}


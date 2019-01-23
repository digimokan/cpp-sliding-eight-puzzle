/*******************************************************************************
module:   EstGoalCostMisplSq
author:   digimokan
date:     23 JAN 2019
purpose:  informed strategy: h(n) = number of misplaced tiles
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostMisplSq.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

EstGoalCostMisplSq::EstGoalCostMisplSq (const Board& goal_board)
  : goal_board{goal_board}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int EstGoalCostMisplSq::get_est_goal_cost (std::shared_ptr<SearchNode> node) const {
  unsigned int est_cost{ 0 };
  const Board cboard{ node->get_board() };
  for (size_t i = 0; i < cboard.get_num_board_squares(); i++) {
    if (cboard.get_square_val(i) != this->goal_board.get_square_val(i))
      est_cost++;
  }
  return est_cost;
}


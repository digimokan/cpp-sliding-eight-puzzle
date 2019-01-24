/*******************************************************************************
module:   EstGoalCostManhatDist
author:   digimokan
date:     24 JAN 2019
purpose:  informed strategy: h(n) = sum of board's manhattan distances
          (each sq manhat dist is num of rows/cols away from its goal position)
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cmath>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostManhatDist.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

EstGoalCostManhatDist::EstGoalCostManhatDist (const Board& goal_board)
  : EstGoalCostInformedBase{goal_board},
    col_locs(goal_board.get_num_board_squares()),
    row_locs(goal_board.get_num_board_squares()) {
  this->calculate_goal_offsets();
}

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int EstGoalCostManhatDist::get_est_goal_cost (std::shared_ptr<SearchNode> node) const {
  unsigned int est_cost{ 0 };
  const size_t num_squares{ this->get_goal_board().get_num_board_squares() };
  const size_t dimension{ static_cast<size_t>(sqrt(num_squares)) };
  const Board cboard{ node->get_board() };
  for (size_t i = 0; i < num_squares; i++) {
    const uint8_t sqval{ cboard.get_square_val(i) };
    const size_t goal_col{ this->col_locs[sqval] };
    const size_t goal_row{ this->row_locs[sqval] };
    size_t icol{ i % dimension };
    size_t irow{ i / dimension };
    const size_t manhat_col{ (icol > goal_col) ? (icol - goal_col) : (goal_col - icol) };
    const size_t manhat_row{ (irow > goal_row) ? (irow - goal_row) : (goal_row - irow) };
    est_cost += (manhat_col + manhat_row);
  }
  return est_cost;
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/


void EstGoalCostManhatDist::calculate_goal_offsets () {
  const Board goal{ this->get_goal_board() };
  const size_t num_squares{ goal.get_num_board_squares() };
  const size_t dimension{ static_cast<size_t>(sqrt(num_squares)) };
  for (size_t i = 0; i < num_squares; i++) {
    const uint8_t sqval{ goal.get_square_val(i) };
    this->col_locs[sqval] = i % dimension;
    this->row_locs[sqval] = i / dimension;
  }
}


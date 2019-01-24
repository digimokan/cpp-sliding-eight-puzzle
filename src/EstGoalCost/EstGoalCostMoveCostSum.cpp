/*******************************************************************************
module:   EstGoalCostMoveCostSum
author:   digimokan
date:     24 JAN 2019
purpose:  informed strategy: h(n) = sum of move costs of current board
          NOTE: this heuristic only makes sense when using MoveCostSqVal
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostMoveCostSum.hpp"
#include "Move.hpp"
#include "MoveCostSqVal.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

EstGoalCostMoveCostSum::EstGoalCostMoveCostSum ()
  : move_gen{std::make_shared<MoveCostSqVal>()}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int EstGoalCostMoveCostSum::get_est_goal_cost (std::shared_ptr<SearchNode> node) const {
  unsigned int est_cost{ 0 };
  for (const auto& move : this->move_gen.generate_moves(node->get_board()))
    est_cost += move.get_cost();
  return est_cost;
}


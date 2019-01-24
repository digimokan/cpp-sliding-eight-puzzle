/*******************************************************************************
module:   EstGoalCostInformedBase
author:   digimokan
date:     23 JAN 2019
purpose:  base class for an informed estimated-goal-cost (considers goal board)
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostInformedBase.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/

EstGoalCostInformedBase::EstGoalCostInformedBase (const Board& goal_board)
  : goal_board{goal_board}
{ }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

Board EstGoalCostInformedBase::get_goal_board () const {
  return this->goal_board;
}


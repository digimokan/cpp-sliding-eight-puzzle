/*******************************************************************************
module:   EstGoalCostBase
author:   digimokan
date:     22 JAN 2019
purpose:  base class for an estimated-goal-cost
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "EstGoalCostBase.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

bool EstGoalCostBase::operator() (const std::shared_ptr<SearchNode>& lh, const std::shared_ptr<SearchNode>& rh) {
  return (this->get_est_goal_cost(lh) > this->get_est_goal_cost(rh));
}


/*******************************************************************************
module:   EstGoalCostUniform
author:   digimokan
date:     17 JAN 2019
purpose:  uninformed strategy: est-cost-to-reach-goal = path cost to curr node
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "EstGoalCostUniform.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int EstGoalCostUniform::get_est_goal_cost (std::shared_ptr<SearchNode> node) const {
  return node->get_path_cost();
}


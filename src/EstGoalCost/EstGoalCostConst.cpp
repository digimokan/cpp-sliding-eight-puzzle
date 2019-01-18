/*******************************************************************************
module:   EstGoalCostConst
author:   digimokan
date:     17 JAN 2019
purpose:  uninformed strategy: return 1, all nodes equally likely to reach goal
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "CompilerUtils.hpp"
#include "EstGoalCostConst.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int EstGoalCostConst::get_est_goal_cost (std::shared_ptr<SearchNode> node) {
  MARK_AS_USED(node);
  return 1u;
}


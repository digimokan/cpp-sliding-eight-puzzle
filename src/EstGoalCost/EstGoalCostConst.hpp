/*******************************************************************************
module:   EstGoalCostConst
author:   digimokan
date:     17 JAN 2019
purpose:  uninformed strategy: return 1, all nodes equally likely to reach goal
*******************************************************************************/

#ifndef EST_GOAL_COST_CONST_HPP
#define EST_GOAL_COST_CONST_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "EstGoalCostIface.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostConst : public EstGoalCostIface {

public:

  // constructors
  EstGoalCostConst () = default;

  // destructor
  ~EstGoalCostConst () override = default;

  // operators
  EstGoalCostConst (const EstGoalCostConst& in) = default;
  EstGoalCostConst& operator= (const EstGoalCostConst& rh) = default;
  EstGoalCostConst (EstGoalCostConst&& in) = default;
  EstGoalCostConst& operator= (EstGoalCostConst&& rh) = default;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_CONST_HPP


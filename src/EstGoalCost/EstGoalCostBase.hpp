/*******************************************************************************
module:   EstGoalCostBase
author:   digimokan
date:     22 JAN 2019
purpose:  base class for an estimated-goal-cost
*******************************************************************************/

#ifndef EST_GOAL_COST_BASE_HPP
#define EST_GOAL_COST_BASE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "EstGoalCostIface.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostBase : public EstGoalCostIface {

public:

  // destructor
  ~EstGoalCostBase () override = default;

  // operators
  EstGoalCostBase (const EstGoalCostBase& in) = default;
  EstGoalCostBase& operator= (const EstGoalCostBase& rh) = delete;
  EstGoalCostBase (EstGoalCostBase&& in) = default;
  EstGoalCostBase& operator= (EstGoalCostBase&& rh) = delete;

  // base / derived methods
  bool operator() (const std::shared_ptr<SearchNode>& lh, const std::shared_ptr<SearchNode>& rh) final;
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override = 0;

protected:

  // constructors
  EstGoalCostBase () = default;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_BASE_HPP


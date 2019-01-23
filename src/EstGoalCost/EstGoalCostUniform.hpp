/*******************************************************************************
module:   EstGoalCostUniform
author:   digimokan
date:     17 JAN 2019
purpose:  uninformed strategy: g(n) = path cost to curr node
*******************************************************************************/

#ifndef EST_GOAL_COST_UNIFORM_HPP
#define EST_GOAL_COST_UNIFORM_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "EstGoalCostBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostUniform : public EstGoalCostBase {

public:

  // constructors
  EstGoalCostUniform () = default;

  // destructor
  ~EstGoalCostUniform () override = default;

  // operators
  EstGoalCostUniform (const EstGoalCostUniform& in) = default;
  EstGoalCostUniform& operator= (const EstGoalCostUniform& rh) = default;
  EstGoalCostUniform (EstGoalCostUniform&& in) = default;
  EstGoalCostUniform& operator= (EstGoalCostUniform&& rh) = default;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_UNIFORM_HPP


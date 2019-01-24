/*******************************************************************************
module:   EstGoalCostInformedBase
author:   digimokan
date:     23 JAN 2019
purpose:  base class for an informed estimated-goal-cost (considers goal board)
*******************************************************************************/

#ifndef EST_GOAL_COST_INFORMED_BASE_HPP
#define EST_GOAL_COST_INFORMED_BASE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostBase.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostInformedBase : public EstGoalCostBase {

public:

  // destructor
  ~EstGoalCostInformedBase () override = default;

  // operators
  EstGoalCostInformedBase (const EstGoalCostInformedBase& in) = default;
  EstGoalCostInformedBase& operator= (const EstGoalCostInformedBase& rh) = delete;
  EstGoalCostInformedBase (EstGoalCostInformedBase&& in) = default;
  EstGoalCostInformedBase& operator= (EstGoalCostInformedBase&& rh) = delete;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override = 0;

protected:

  // constructors
  explicit EstGoalCostInformedBase (const Board& goal_board);

  // specialized methods
  Board get_goal_board () const;

private:

  const Board goal_board;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_INFORMED_BASE_HPP


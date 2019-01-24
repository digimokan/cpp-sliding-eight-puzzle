/*******************************************************************************
module:   EstGoalCostMoveCostSum
author:   digimokan
date:     24 JAN 2019
purpose:  informed strategy: h(n) = sum of move costs of current board
          NOTE: this heuristic only makes sense when using MoveCostSqVal
*******************************************************************************/

#ifndef EST_GOAL_COST_MOVE_COST_SUM_HPP
#define EST_GOAL_COST_MOVE_COST_SUM_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostBase.hpp"
#include "MoveGenerator.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostMoveCostSum : public EstGoalCostBase {

public:

  // constructors
  EstGoalCostMoveCostSum ();

  // destructor
  ~EstGoalCostMoveCostSum () override = default;

  // operators
  EstGoalCostMoveCostSum (const EstGoalCostMoveCostSum& in) = delete;
  EstGoalCostMoveCostSum& operator= (const EstGoalCostMoveCostSum& rh) = delete;
  EstGoalCostMoveCostSum (EstGoalCostMoveCostSum&& in) = delete;
  EstGoalCostMoveCostSum& operator= (EstGoalCostMoveCostSum&& rh) = delete;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override;

private:

  // fields
  MoveGenerator move_gen;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_MOVE_COST_SUM_HPP


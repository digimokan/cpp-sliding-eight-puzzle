/*******************************************************************************
module:   EstGoalCostAstarOne
author:   digimokan
date:     24 JAN 2019
purpose:  A*1 informed strategy, f(n) = combination of these two strategies:
            1. g(n) = uniform cost
            2. h(n) = number of misplaced tiles
*******************************************************************************/

#ifndef EST_GOAL_COST_ASTAR_ONE_HPP
#define EST_GOAL_COST_ASTAR_ONE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostBase.hpp"
#include "EstGoalCostMisplSq.hpp"
#include "EstGoalCostUniform.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostAstarOne : public EstGoalCostBase {

public:

  // constructors
  EstGoalCostAstarOne () = delete;
  explicit EstGoalCostAstarOne (const Board& goal_board);

  // destructor
  ~EstGoalCostAstarOne () override = default;

  // operators
  EstGoalCostAstarOne (const EstGoalCostAstarOne& in) = default;
  EstGoalCostAstarOne& operator= (const EstGoalCostAstarOne& rh) = delete;
  EstGoalCostAstarOne (EstGoalCostAstarOne&& in) = default;
  EstGoalCostAstarOne& operator= (EstGoalCostAstarOne&& rh) = delete;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override;

private:

  // fields
  const EstGoalCostUniform est_cost_uniform;
  const EstGoalCostMisplSq est_cost_mispl_sq;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_ASTAR_ONE_HPP


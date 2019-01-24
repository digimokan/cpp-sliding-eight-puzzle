/*******************************************************************************
module:   EstGoalCostAstarTwo
author:   digimokan
date:     24 JAN 2019
purpose:  A*2 informed strategy, f(n) = combination of these two strategies:
            1. g(n) = uniform cost
            2. h(n) = sum of board's manhattan distances
*******************************************************************************/

#ifndef EST_GOAL_COST_ASTAR_TWO_HPP
#define EST_GOAL_COST_ASTAR_TWO_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostBase.hpp"
#include "EstGoalCostManhatDist.hpp"
#include "EstGoalCostUniform.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostAstarTwo : public EstGoalCostBase {

public:

  // constructors
  EstGoalCostAstarTwo () = delete;
  explicit EstGoalCostAstarTwo (const Board& goal_board);

  // destructor
  ~EstGoalCostAstarTwo () override = default;

  // operators
  EstGoalCostAstarTwo (const EstGoalCostAstarTwo& in) = default;
  EstGoalCostAstarTwo& operator= (const EstGoalCostAstarTwo& rh) = delete;
  EstGoalCostAstarTwo (EstGoalCostAstarTwo&& in) = default;
  EstGoalCostAstarTwo& operator= (EstGoalCostAstarTwo&& rh) = delete;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override;

private:

  // fields
  const EstGoalCostUniform est_cost_uniform;
  const EstGoalCostManhatDist est_cost_manhat_dist;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_ASTAR_TWO_HPP


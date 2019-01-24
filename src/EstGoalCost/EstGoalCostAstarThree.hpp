/*******************************************************************************
module:   EstGoalCostAstarThree
author:   digimokan
date:     24 JAN 2019
purpose:  A*3 informed strategy, f(n) = combination of these three strategies:
            1. g(n) = uniform cost
            2. h(n) = sum of board's manhattan distances
            3. h(n) = sum of costs of board's possible moves
*******************************************************************************/

#ifndef EST_GOAL_COST_ASTAR_THREE_HPP
#define EST_GOAL_COST_ASTAR_THREE_HPP 1

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
#include "EstGoalCostMoveCostSum.hpp"
#include "EstGoalCostUniform.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostAstarThree : public EstGoalCostBase {

public:

  // constructors
  EstGoalCostAstarThree () = delete;
  explicit EstGoalCostAstarThree (const Board& goal_board);

  // destructor
  ~EstGoalCostAstarThree () override = default;

  // operators
  EstGoalCostAstarThree (const EstGoalCostAstarThree& in) = default;
  EstGoalCostAstarThree& operator= (const EstGoalCostAstarThree& rh) = delete;
  EstGoalCostAstarThree (EstGoalCostAstarThree&& in) = default;
  EstGoalCostAstarThree& operator= (EstGoalCostAstarThree&& rh) = delete;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override;

private:

  // fields
  const EstGoalCostUniform est_cost_uniform;
  const EstGoalCostManhatDist est_cost_manhat_dist;
  const EstGoalCostMoveCostSum est_cost_move_cost_sum;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_ASTAR_THREE_HPP


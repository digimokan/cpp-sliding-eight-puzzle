/*******************************************************************************
module:   EstGoalCostManhatDist
author:   digimokan
date:     24 JAN 2019
purpose:  informed strategy: h(n) = sum of board's manhattan distances
          (each sq manhat dist is num of rows/cols away from its goal position)
*******************************************************************************/

#ifndef EST_GOAL_COST_MANHAT_DIST_HPP
#define EST_GOAL_COST_MANHAT_DIST_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>
#include <vector>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "EstGoalCostInformedBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostManhatDist : public EstGoalCostInformedBase {

public:

  // constructors
  EstGoalCostManhatDist () = delete;
  explicit EstGoalCostManhatDist (const Board& goal_board);

  // destructor
  ~EstGoalCostManhatDist () override = default;

  // operators
  EstGoalCostManhatDist (const EstGoalCostManhatDist& in) = default;
  EstGoalCostManhatDist& operator= (const EstGoalCostManhatDist& rh) = delete;
  EstGoalCostManhatDist (EstGoalCostManhatDist&& in) = default;
  EstGoalCostManhatDist& operator= (EstGoalCostManhatDist&& rh) = delete;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override;

private:

  // fields
  std::vector<size_t> col_locs;
  std::vector<size_t> row_locs;

  // helper methods
  void calculate_goal_offsets ();

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_MANHAT_DIST_HPP


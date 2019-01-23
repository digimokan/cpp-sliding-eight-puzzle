/*******************************************************************************
module:   EstGoalCostMisplSq
author:   digimokan
date:     23 JAN 2019
purpose:  informed strategy: h(n) = number of misplaced tiles
*******************************************************************************/

#ifndef EST_GOAL_COST_MISPL_SQ_HPP
#define EST_GOAL_COST_MISPL_SQ_HPP 1

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
* FORWARD DECLARES
*******************************************************************************/

class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class EstGoalCostMisplSq : public EstGoalCostBase {

public:

  // constructors
  EstGoalCostMisplSq () = delete;
  explicit EstGoalCostMisplSq (const Board& goal_board);

  // destructor
  ~EstGoalCostMisplSq () override = default;

  // operators
  EstGoalCostMisplSq (const EstGoalCostMisplSq& in) = default;
  EstGoalCostMisplSq& operator= (const EstGoalCostMisplSq& rh) = delete;
  EstGoalCostMisplSq (EstGoalCostMisplSq&& in) = default;
  EstGoalCostMisplSq& operator= (EstGoalCostMisplSq&& rh) = delete;

  // base / derived methods
  unsigned int get_est_goal_cost (std::shared_ptr<SearchNode> node) const override;

private:

  const Board goal_board;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // EST_GOAL_COST_MISPL_SQ_HPP


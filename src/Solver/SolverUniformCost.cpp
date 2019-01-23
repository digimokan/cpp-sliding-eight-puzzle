/*******************************************************************************
module:   SolverUniformCost
author:   digimokan
date:     23 JAN 2019
purpose:  solve an eight-puzzle using uniform-cost search
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "EstGoalCostUniform.hpp"
#include "FrontierQueueEstCost.hpp"
#include "MoveCostIface.hpp"
#include "SolverUniformCost.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SolverUniformCost::SolverUniformCost (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost)
  : SolverEstGoalCostBase{start_board, goal_board, move_cost,
      std::make_shared<EstGoalCostUniform>(),
      std::make_shared<FrontierQueueEstCost<EstGoalCostUniform>>()}
{ }


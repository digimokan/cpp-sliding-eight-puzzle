/*******************************************************************************
module:   SolverBFS
author:   digimokan
date:     20 JAN 2019
purpose:  solve an eight-puzzle using bfs search
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBFS.hpp"
#include "SolverBFS.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SolverBFS::SolverBFS (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost)
  : SolverBfsDfsBase{start_board, goal_board, move_cost, std::make_shared<FrontierQueueBFS>()}
{ }


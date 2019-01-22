/*******************************************************************************
module:   SolverDFS
author:   digimokan
date:     21 JAN 2019
purpose:  solve an eight-puzzle using dfs search
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueDFS.hpp"
#include "SolverDFS.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SolverDFS::SolverDFS (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost)
  : SolverBfsDfsBase{start_board, goal_board, move_cost, std::make_shared<FrontierQueueDFS>()}
{ }


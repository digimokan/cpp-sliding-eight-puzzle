/*******************************************************************************
module:   SolverLimitedDFS
author:   digimokan
date:     21 JAN 2019
purpose:  solve an eight-puzzle using dfs search, limited to a max-search-depth
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueDFS.hpp"
#include "SolverLimitedDFS.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SolverLimitedDFS::SolverLimitedDFS (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost, size_t max_search_depth)
  : SolverBfsDfsBase{start_board, goal_board, move_cost, std::make_shared<FrontierQueueDFS>(), max_search_depth}
{ }


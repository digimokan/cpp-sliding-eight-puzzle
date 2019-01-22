/*******************************************************************************
module:   SolverLimitedDFS
author:   digimokan
date:     21 JAN 2019
purpose:  solve an eight-puzzle using dfs search, limited to a max-search-depth
*******************************************************************************/

#ifndef SOLVER_DFS_HPP
#define SOLVER_DFS_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "SolverBfsDfsBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;
class MoveCostIface;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverLimitedDFS : public SolverBfsDfsBase  {

public:

  // constructors
  SolverLimitedDFS () = delete;
  explicit SolverLimitedDFS (Board start_board, Board goal_board, const std::shared_ptr<MoveCostIface>& move_cost, size_t max_search_depth);

  // destructor
  ~SolverLimitedDFS () override = default;

  // operators
  SolverLimitedDFS (const SolverLimitedDFS& in) = delete;
  SolverLimitedDFS& operator= (const SolverLimitedDFS& rh) = delete;
  SolverLimitedDFS (SolverLimitedDFS&& in) = delete;
  SolverLimitedDFS& operator= (SolverLimitedDFS&& rh) = delete;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_DFS_HPP


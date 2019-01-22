/*******************************************************************************
module:   SolverDFS
author:   digimokan
date:     21 JAN 2019
purpose:  solve an eight-puzzle using dfs search
*******************************************************************************/

#ifndef SOLVER_DFS_HPP
#define SOLVER_DFS_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

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

class SolverDFS : public SolverBfsDfsBase  {

public:

  // constructors
  SolverDFS () = delete;
  explicit SolverDFS (Board start_board, Board goal_board, const std::shared_ptr<MoveCostIface>& move_cost);

  // destructor
  ~SolverDFS () override = default;

  // operators
  SolverDFS (const SolverDFS& in) = delete;
  SolverDFS& operator= (const SolverDFS& rh) = delete;
  SolverDFS (SolverDFS&& in) = delete;
  SolverDFS& operator= (SolverDFS&& rh) = delete;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_DFS_HPP


/*******************************************************************************
module:   SolverBFS
author:   digimokan
date:     20 JAN 2019
purpose:  solve an eight-puzzle using bfs search
*******************************************************************************/

#ifndef SOLVER_BFS_HPP
#define SOLVER_BFS_HPP 1

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

class SolverBFS : public SolverBfsDfsBase  {

public:

  // constructors
  SolverBFS () = delete;
  explicit SolverBFS (Board start_board, Board goal_board, const std::shared_ptr<MoveCostIface>& move_cost);

  // destructor
  ~SolverBFS () override = default;

  // operators
  SolverBFS (const SolverBFS& in) = delete;
  SolverBFS& operator= (const SolverBFS& rh) = delete;
  SolverBFS (SolverBFS&& in) = delete;
  SolverBFS& operator= (SolverBFS&& rh) = delete;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_BFS_HPP


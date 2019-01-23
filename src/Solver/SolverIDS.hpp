/*******************************************************************************
module:   SolverIDS
author:   digimokan
date:     20 JAN 2019
purpose:  base Solver impl class for BFS/DFS Solvers
*******************************************************************************/

#ifndef SOLVER_IDS_HPP
#define SOLVER_IDS_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "Solution.hpp"
#include "SolverIface.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class MoveCostIface;
class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverIDS : public SolverIface {

public:

  // constructors
  explicit SolverIDS (Board start_board, Board goal_board, std::shared_ptr<MoveCostIface> move_cost);

  // constructors
  SolverIDS () = delete;

  // destructor
  ~SolverIDS () override = default;

  // operators
  SolverIDS (const SolverIDS& in) = delete;
  SolverIDS& operator= (const SolverIDS& rh) = delete;
  SolverIDS (SolverIDS&& in) = delete;
  SolverIDS& operator= (SolverIDS&& rh) = delete;

  // base / derived methods
  Solution solve () final;

private:

  // fields
  const Board start_board;
  const Board goal_board;
  std::shared_ptr<MoveCostIface> move_cost;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_IDS_HPP


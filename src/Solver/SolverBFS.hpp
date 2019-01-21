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
#include <optional>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "SolverBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;
class MoveCostIface;
class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverBFS : public SolverBase  {

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

  // base / derived methods
  std::optional<Solution> solve () final;

private:

  // base / derived methods
  void act_on_expanded_node (const std::shared_ptr<SearchNode>& enode) final;

  // helper methods
  void check_if_root_is_goal ();

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_BFS_HPP


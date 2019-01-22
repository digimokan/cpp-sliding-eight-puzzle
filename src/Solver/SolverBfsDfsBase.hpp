/*******************************************************************************
module:   SolverBfsDfsBase
author:   digimokan
date:     20 JAN 2019
purpose:  base Solver impl class for BFS/DFS Solvers
*******************************************************************************/

#ifndef SOLVER_BFS_DFS_BASE_HPP
#define SOLVER_BFS_DFS_BASE_HPP 1

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
class FrontierQueueIface;
class MoveCostIface;
class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverBfsDfsBase : public SolverBase  {

public:

  // constructors
  SolverBfsDfsBase () = delete;

  // destructor
  ~SolverBfsDfsBase () override = default;

  // operators
  SolverBfsDfsBase (const SolverBfsDfsBase& in) = delete;
  SolverBfsDfsBase& operator= (const SolverBfsDfsBase& rh) = delete;
  SolverBfsDfsBase (SolverBfsDfsBase&& in) = delete;
  SolverBfsDfsBase& operator= (SolverBfsDfsBase&& rh) = delete;

  // base / derived methods
  std::optional<Solution> solve () final;

protected:

  // constructors
  explicit SolverBfsDfsBase (Board start_board, Board goal_board, const std::shared_ptr<MoveCostIface>& move_cost, std::shared_ptr<FrontierQueueIface>);

private:

  // base / derived methods
  void act_on_expanded_node (const std::shared_ptr<SearchNode>& enode) final;

  // helper methods
  void check_if_root_is_goal ();
  void keep_lowest_cost_fq_node (const std::shared_ptr<SearchNode>& exp_node, const std::shared_ptr<SearchNode>& fq_node);

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_BFS_DFS_BASE_HPP


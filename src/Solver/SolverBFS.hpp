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

#include "Board.hpp"
#include "BoardMap.hpp"
#include "FrontierQueueBFS.hpp"
#include "SearchGraph.hpp"
#include "SolverIface.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class MoveCostIface;
class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverBFS : public SolverIface  {

public:

  // constructors
  SolverBFS () = delete;
  explicit SolverBFS (Board start_board, Board goal_board, std::shared_ptr<MoveCostIface> move_cost);

  // destructor
  ~SolverBFS () override = default;

  // operators
  SolverBFS (const SolverBFS& in) = delete;
  SolverBFS& operator= (const SolverBFS& rh) = delete;
  SolverBFS (SolverBFS&& in) = delete;
  SolverBFS& operator= (SolverBFS&& rh) = delete;

  // base / derived methods
  std::optional<Solution> solve () override;

private:

  // fields
  const Board goal_board;
  SearchGraph search_graph;
  FrontierQueueBFS fq;
  BoardMap search_history;
  std::optional<std::shared_ptr<SearchNode>> found_goal_node;

  // helper methods
  void check_if_root_is_goal ();
  void expand_frontier (const std::shared_ptr<SearchNode>& frontier_node);
  bool is_goal (const std::shared_ptr<SearchNode>& node) const;
  std::optional<Solution> make_solution (std::optional<std::shared_ptr<SearchNode>> goal_node) const;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_BFS_HPP


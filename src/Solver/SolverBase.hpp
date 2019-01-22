/*******************************************************************************
module:   SolverBase
author:   digimokan
date:     20 JAN 2019
purpose:  base SolverIface impl class with common methods
*******************************************************************************/

#ifndef SOLVER_BASE_HPP
#define SOLVER_BASE_HPP 1

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
#include "SolverIface.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class FrontierQueueIface;
class MoveCostIface;
class SearchGraph;
class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverBase : public SolverIface {

public:

  // constructors
  SolverBase () = delete;

  // destructor
  ~SolverBase () override = default;

  // operators
  SolverBase (const SolverBase& in) = delete;
  SolverBase& operator= (const SolverBase& rh) = delete;
  SolverBase (SolverBase&& in) = delete;
  SolverBase& operator= (SolverBase&& rh) = delete;

  // base / derived methods
  std::optional<Solution> solve () override = 0;

protected:

  // constructors
  explicit SolverBase (Board start_board, Board goal_board, const std::shared_ptr<MoveCostIface>& move_cost, std::shared_ptr<FrontierQueueIface> frontier_queue);

  // base / derived methods
  virtual void act_on_expanded_node (const std::shared_ptr<SearchNode>& enode) = 0;

  // specialized methods
  void expand_frontier (const std::shared_ptr<SearchNode>& frontier_node);
  void fq_push (std::shared_ptr<SearchNode>);
  std::shared_ptr<SearchNode> fq_pop ();
  bool fq_contains (const Board&) const;
  bool fq_not_contains (const Board&) const;
  std::optional<std::shared_ptr<SearchNode>> fq_get_node (const Board& board) const;
  void fq_remove_node (const std::shared_ptr<SearchNode>& node);
  bool fq_is_empty () const;
  bool fq_not_empty () const;
  bool is_in_history (const Board& board) const;
  bool not_in_history (const Board& board) const;
  void add_to_history (std::shared_ptr<SearchNode>);
  std::optional<std::shared_ptr<SearchNode>> get_history_node (const Board& board) const;
  bool is_goal (const std::shared_ptr<SearchNode>& node) const;
  bool found_goal_node () const;
  bool not_found_goal_node () const;
  void set_goal_node (std::shared_ptr<SearchNode>);
  std::shared_ptr<SearchNode> get_goal_node () const;
  std::optional<Solution> make_solution_from_goal_node () const;

private:

  // fields
  const Board goal_board;
  std::shared_ptr<SearchGraph> search_graph;
  std::shared_ptr<FrontierQueueIface> fq;
  BoardMap search_history;
  std::optional<std::shared_ptr<SearchNode>> goal_node;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_BASE_HPP


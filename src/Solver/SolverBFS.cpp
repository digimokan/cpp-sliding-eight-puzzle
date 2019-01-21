/*******************************************************************************
module:   SolverBFS
author:   digimokan
date:     20 JAN 2019
purpose:  solve an eight-puzzle using bfs search
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <functional>
#include <memory>
#include <optional>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "BoardMap.hpp"
#include "FrontierQueueBFS.hpp"
#include "MoveCostIface.hpp"
#include "SearchGraph.hpp"
#include "SearchNode.hpp"
#include "Solution.hpp"
#include "SolverBFS.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SolverBFS::SolverBFS (Board start_board, Board goal_board,
      std::shared_ptr<MoveCostIface> move_cost)
  : goal_board{goal_board},
    search_graph{std::make_shared<SearchNode>(start_board), std::move(move_cost)},
    found_goal_node{std::nullopt}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

std::optional<Solution> SolverBFS::solve () {
  this->check_if_root_is_goal();
  while ( (this->fq.not_empty()) && (! this->found_goal_node.has_value()) ) {
    auto fnode{ this->fq.pop() };
    this->search_history.add(fnode);
    this->expand_frontier(fnode);
  }
  return this->make_solution(this->found_goal_node);
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

void SolverBFS::check_if_root_is_goal () {
  if (this->is_goal(this->search_graph.get_root()))
    this->found_goal_node = this->search_graph.get_root();
  else
    this->fq.push(this->search_graph.get_root());
}

void SolverBFS::expand_frontier (const std::shared_ptr<SearchNode>& frontier_node) {
  auto act_on_expanded = [this] (auto exp_node) {
    if (this->fq.not_contains(exp_node->get_board()) && this->search_history.not_contains(exp_node->get_board())) {
      if (this->is_goal(exp_node))
        this->found_goal_node = exp_node;
      else
        this->fq.push(exp_node);
    }
  };
  this->search_graph.expand(frontier_node, act_on_expanded);
}

bool SolverBFS::is_goal (const std::shared_ptr<SearchNode>& node) const {
  return (node->get_board() == this->goal_board);
}

std::optional<Solution> SolverBFS::make_solution (std::optional<std::shared_ptr<SearchNode>> goal_node) const {
  if (! goal_node.has_value())
    return std::nullopt;
  return Solution{
    this->fq.get_num_nodes_popped(),
    this->fq.get_largest_queue_size(),
    goal_node.value()
  };
}


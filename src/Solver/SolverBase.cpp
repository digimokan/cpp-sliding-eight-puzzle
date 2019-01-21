/*******************************************************************************
module:   SolverBase
author:   digimokan
date:     20 JAN 2019
purpose:  base SolverIface impl class with common methods
*******************************************************************************/

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
#include "FrontierQueueIface.hpp"
#include "MoveCostIface.hpp"
#include "SearchGraph.hpp"
#include "SearchNode.hpp"
#include "Solution.hpp"
#include "SolverBase.hpp"

/*******************************************************************************
* CONSTRUCTOR
*******************************************************************************/

SolverBase::SolverBase (Board start_board, Board goal_board,
    const std::shared_ptr<MoveCostIface>& move_cost,
    std::shared_ptr<FrontierQueueIface> frontier_queue)
  : goal_board{goal_board},
    search_graph{std::make_shared<SearchGraph>(std::make_shared<SearchNode>(start_board), move_cost)},
    fq{std::move(frontier_queue)},
    goal_node{std::nullopt} {
  this->fq_push(this->search_graph->get_root());
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

void SolverBase::expand_frontier (const std::shared_ptr<SearchNode>& frontier_node) {
  auto act = [this] (auto exp_node) { this->act_on_expanded_node(exp_node); };
  this->search_graph->expand(frontier_node, act);
}

void SolverBase::fq_push (std::shared_ptr<SearchNode> node) {
  this->fq->push(std::move(node));
}

std::shared_ptr<SearchNode> SolverBase::fq_pop () {
  return this->fq->pop();
}

bool SolverBase::fq_contains (const Board& board) const {
  return this->fq->contains(board);
}

bool SolverBase::fq_not_contains (const Board& board) const {
  return this->fq->not_contains(board);
}

bool SolverBase::fq_is_empty () const {
  return this->fq->is_empty();
}

bool SolverBase::fq_not_empty () const {
  return this->fq->not_empty();
}

bool SolverBase::is_in_history (const Board& board) const {
  return this->search_history.contains(board);
}

bool SolverBase::not_in_history (const Board& board) const {
  return (this->search_history.not_contains(board));
}

void SolverBase::add_to_history (std::shared_ptr<SearchNode> node) {
  this->search_history.add(std::move(node));
}

bool SolverBase::is_goal (const std::shared_ptr<SearchNode>& node) const {
  return (node->get_board() == this->goal_board);
}

bool SolverBase::found_goal_node () const {
  return this->goal_node.has_value();
}

bool SolverBase::not_found_goal_node () const {
  return (! this->found_goal_node());
}

void SolverBase::set_goal_node (std::shared_ptr<SearchNode> node) {
  this->goal_node = node;
}

std::shared_ptr<SearchNode> SolverBase::get_goal_node () const {
  return this->goal_node.value();
}

std::optional<Solution> SolverBase::make_solution_from_goal_node () const {
  if (this->not_found_goal_node())
    return std::nullopt;
  return Solution{
    this->fq->get_num_nodes_popped(),
    this->fq->get_largest_queue_size(),
    this->get_goal_node()
  };
}


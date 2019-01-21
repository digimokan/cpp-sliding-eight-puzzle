/*******************************************************************************
module:   SolverBFS
author:   digimokan
date:     20 JAN 2019
purpose:  solve an eight-puzzle using bfs search
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>
#include <optional>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBFS.hpp"
#include "Solution.hpp"
#include "SolverBFS.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SolverBFS::SolverBFS (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost)
  : SolverBase{start_board, goal_board, move_cost, std::make_shared<FrontierQueueBFS>()}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

std::optional<Solution> SolverBFS::solve () {
  this->check_if_root_is_goal();
  while ( (this->fq_not_empty()) && (this->not_found_goal_node()) ) {
    auto fnode{ this->fq_pop() };
    this->add_to_history(fnode);
    this->expand_frontier(fnode);
  }
  return this->make_solution_from_goal_node();
}

void SolverBFS::act_on_expanded_node (const std::shared_ptr<SearchNode>& enode) {
  if (this->fq_not_contains(enode->get_board()) && this->not_in_history(enode->get_board())) {
    if (this->is_goal(enode))
      this->set_goal_node(enode);
    else
      this->fq_push(enode);
  }
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

void SolverBFS::check_if_root_is_goal () {
  auto fnode{ this->fq_pop() };
  if (this->is_goal(fnode))
    this->set_goal_node(fnode);
  else
    this->fq_push(fnode);
}


/*******************************************************************************
module:   SolverEstGoalCostBase
author:   digimokan
date:     20 JAN 2019
purpose:  base Solver impl class for BFS/DFS Solvers
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
#include "EstGoalCostIface.hpp"
#include "FrontierQueueIface.hpp"
#include "MoveCostIface.hpp"
#include "SearchNode.hpp"
#include "Solution.hpp"
#include "SolverEstGoalCostBase.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SolverEstGoalCostBase::SolverEstGoalCostBase (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost,
      std::shared_ptr<EstGoalCostIface> est_cost,
      std::shared_ptr<FrontierQueueIface> frontier_queue,
      std::optional<size_t> max_search_depth)
  : SolverBase{start_board, goal_board, move_cost, std::move(frontier_queue), max_search_depth},
    est_cost{std::move(est_cost)}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

Solution SolverEstGoalCostBase::solve () {
  while (true) {
    if (this->fq_is_empty())
      return this->make_solution_from_goal_node();
    auto node{ this->fq_pop() };
    if (this->is_goal(node)) {
      this->set_goal_node(node);
      return this->make_solution_from_goal_node();
    }
    this->add_to_history(node);
    this->expand_frontier(node);
  }
}

void SolverEstGoalCostBase::act_on_expanded_node (const std::shared_ptr<SearchNode>& enode) {
  if (this->fq_contains(enode->get_board()))
    this->keep_lowest_cost_fq_node(enode, this->fq_get_node(enode->get_board()).value());
  else if (this->not_in_history(enode->get_board()))
    this->push_to_fq_on_depth_limit(enode);
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

void SolverEstGoalCostBase::keep_lowest_cost_fq_node (const std::shared_ptr<SearchNode>& exp_node,
    const std::shared_ptr<SearchNode>& fq_node) {
  if (this->est_cost->get_est_goal_cost(exp_node) < this->est_cost->get_est_goal_cost(fq_node)) {
    this->fq_remove_node(fq_node);
    this->fq_push(exp_node);
  }
}


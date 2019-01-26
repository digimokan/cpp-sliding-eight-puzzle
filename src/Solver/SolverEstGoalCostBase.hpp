/*******************************************************************************
module:   SolverEstGoalCostBase
author:   digimokan
date:     22 JAN 2019
purpose:  base Solver impl class for uniform-cost or f(n) Solvers
*******************************************************************************/

#ifndef SOLVER_EST_GOAL_COST_BASE_HPP
#define SOLVER_EST_GOAL_COST_BASE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <memory>
#include <optional>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Solution.hpp"
#include "SolverBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;
class EstGoalCostIface;
class FrontierQueueIface;
class MoveCostIface;
class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverEstGoalCostBase : public SolverBase  {

public:

  // constructors
  SolverEstGoalCostBase () = delete;

  // destructor
  ~SolverEstGoalCostBase () override = default;

  // operators
  SolverEstGoalCostBase (const SolverEstGoalCostBase& in) = delete;
  SolverEstGoalCostBase& operator= (const SolverEstGoalCostBase& rh) = delete;
  SolverEstGoalCostBase (SolverEstGoalCostBase&& in) = delete;
  SolverEstGoalCostBase& operator= (SolverEstGoalCostBase&& rh) = delete;

  // base / derived methods
  Solution solve () final;

protected:

  // constructors
  explicit SolverEstGoalCostBase (Board start_board, Board goal_board, const std::shared_ptr<MoveCostIface>& move_cost, std::shared_ptr<EstGoalCostIface> est_cost, std::shared_ptr<FrontierQueueIface> frontier_queue, std::optional<size_t> max_search_depth = std::nullopt);

private:

  // fields
  const std::shared_ptr<EstGoalCostIface> est_cost;

  // base / derived methods
  void act_on_expanded_node (const std::shared_ptr<SearchNode>& enode) final;

  // helper methods
  void keep_lowest_cost_fq_node (const std::shared_ptr<SearchNode>& exp_node, const std::shared_ptr<SearchNode>& fq_node);

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_EST_GOAL_COST_BASE_HPP


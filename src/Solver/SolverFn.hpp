/*******************************************************************************
module:   SolverFn
author:   digimokan
date:     23 JAN 2019
purpose:  template class for solver that uses uniform, f(n), g(n), etc.
template params:
          T - an implementation of EstGoalCostIface
*******************************************************************************/

#ifndef SOLVER_UNIFORM_COST_HPP
#define SOLVER_UNIFORM_COST_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "FrontierQueueEstCost.hpp"
#include "MoveCostIface.hpp"
#include "SolverEstGoalCostBase.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

template <typename T>
class SolverFn : public SolverEstGoalCostBase  {

public:

  // constructors
  SolverFn () = delete;
  explicit SolverFn (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost)
  : SolverEstGoalCostBase{start_board, goal_board,
      move_cost,
      std::make_shared<T>(),
      std::make_shared<FrontierQueueEstCost<T>>()}
  { }

  // destructor
  ~SolverFn () override = default;

  // operators
  SolverFn (const SolverFn& in) = delete;
  SolverFn& operator= (const SolverFn& rh) = delete;
  SolverFn (SolverFn&& in) = delete;
  SolverFn& operator= (SolverFn&& rh) = delete;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_UNIFORM_COST_HPP


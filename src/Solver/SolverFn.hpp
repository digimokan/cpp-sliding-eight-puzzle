/*******************************************************************************
module:   SolverFn
author:   digimokan
date:     23 JAN 2019
purpose:  template class for solver that uses uniform, f(n), g(n), etc.
template params:
          T - an implementation of MoveCostIface
          U - an implementation of EstGoalCostIface
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
#include "SolverEstGoalCostBase.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

template <typename T, typename U>
class SolverFn : public SolverEstGoalCostBase  {

public:

  // constructors
  SolverFn () = delete;
  explicit SolverFn (Board start_board, Board goal_board)
  : SolverEstGoalCostBase{start_board, goal_board,
      std::make_shared<T>(),
      std::make_shared<U>(),
      std::make_shared<FrontierQueueEstCost<U>>()}
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


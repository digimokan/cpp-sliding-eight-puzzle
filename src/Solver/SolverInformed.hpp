/*******************************************************************************
module:   SolverInformed
author:   digimokan
date:     23 JAN 2019
purpose:  template class for solver that uses informed search (f(n), g(n), h(n))
template params:
          T - an informed implementation of EstGoalCostIface (takes goal board)
*******************************************************************************/

#ifndef SOLVER_INFORMED_HPP
#define SOLVER_INFORMED_HPP 1

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
class SolverInformed : public SolverEstGoalCostBase  {

public:

  // constructors
  SolverInformed () = delete;
  explicit SolverInformed (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost)
  : SolverEstGoalCostBase{start_board, goal_board,
      move_cost,
      std::make_shared<T>(goal_board),
      std::make_shared<FrontierQueueEstCost<T>>(goal_board)}
  { }

  // destructor
  ~SolverInformed () override = default;

  // operators
  SolverInformed (const SolverInformed& in) = delete;
  SolverInformed& operator= (const SolverInformed& rh) = delete;
  SolverInformed (SolverInformed&& in) = delete;
  SolverInformed& operator= (SolverInformed&& rh) = delete;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_INFORMED_HPP


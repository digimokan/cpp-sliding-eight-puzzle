/*******************************************************************************
module:   SolverUninformed
author:   digimokan
date:     23 JAN 2019
purpose:  template class for solver that uses uninformed search (uniform, etc.)
template params:
          T - an uninformed implementation of EstGoalCostIface (no ctor args)
*******************************************************************************/

#ifndef SOLVER_UNINFORMED_HPP
#define SOLVER_UNINFORMED_HPP 1

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
class SolverUninformed : public SolverEstGoalCostBase  {

public:

  // constructors
  SolverUninformed () = delete;
  explicit SolverUninformed (Board start_board, Board goal_board,
      const std::shared_ptr<MoveCostIface>& move_cost)
  : SolverEstGoalCostBase{start_board, goal_board,
      move_cost,
      std::make_shared<T>(),
      std::make_shared<FrontierQueueEstCost<T>>()}
  { }

  // destructor
  ~SolverUninformed () override = default;

  // operators
  SolverUninformed (const SolverUninformed& in) = delete;
  SolverUninformed& operator= (const SolverUninformed& rh) = delete;
  SolverUninformed (SolverUninformed&& in) = delete;
  SolverUninformed& operator= (SolverUninformed&& rh) = delete;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_UNINFORMED_HPP


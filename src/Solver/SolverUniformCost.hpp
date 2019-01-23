/*******************************************************************************
module:   SolverUniformCost
author:   digimokan
date:     23 JAN 2019
purpose:  solve an eight-puzzle using uniform-cost search
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

#include "SolverEstGoalCostBase.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;
class MoveCostIface;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SolverUniformCost : public SolverEstGoalCostBase  {

public:

  // constructors
  SolverUniformCost () = delete;
  explicit SolverUniformCost (Board start_board, Board goal_board, const std::shared_ptr<MoveCostIface>& move_cost);

  // destructor
  ~SolverUniformCost () override = default;

  // operators
  SolverUniformCost (const SolverUniformCost& in) = delete;
  SolverUniformCost& operator= (const SolverUniformCost& rh) = delete;
  SolverUniformCost (SolverUniformCost&& in) = delete;
  SolverUniformCost& operator= (SolverUniformCost&& rh) = delete;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLVER_UNIFORM_COST_HPP


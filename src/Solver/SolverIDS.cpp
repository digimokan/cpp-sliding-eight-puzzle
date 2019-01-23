/*******************************************************************************
module:   SolverIDS
author:   digimokan
date:     20 JAN 2019
purpose:  base Solver impl class for BFS/DFS Solvers
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Solution.hpp"
#include "SolverIDS.hpp"
#include "SolverLimitedDFS.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SolverIDS::SolverIDS (Board start_board, Board goal_board,
      std::shared_ptr<MoveCostIface> move_cost)
  : start_board{start_board},
    goal_board{goal_board},
    move_cost{std::move(move_cost)}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

Solution SolverIDS::solve () {
  size_t max_depth{ 0 };
  size_t sum_time_complexity{ 0 };
  size_t sum_space_complexity{ 0 };
  while(true) {
    SolverLimitedDFS solver{ this->start_board, this->goal_board, this->move_cost, max_depth };
    Solution solution{ solver.solve() };
    sum_time_complexity += solution.get_time_complexity();
    sum_space_complexity += solution.get_space_complexity();
    if (solution.is_solved())
      return Solution{ sum_time_complexity, sum_space_complexity, solution };
    max_depth++;
  }
}


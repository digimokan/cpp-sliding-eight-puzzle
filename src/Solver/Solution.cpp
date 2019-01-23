/*******************************************************************************
module:   Solution
author:   digimokan
date:     17 JAN 2019
purpose:  holds solution steps/info for a solved eight-puzzle
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <deque>
#include <functional>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "SearchNode.hpp"
#include "Solution.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

Solution::Solution (size_t time_complexity, size_t space_complexity)
  : solved{false},
    time_complexity{time_complexity},
    space_complexity{space_complexity}
{ }

Solution::Solution (size_t time_complexity, size_t space_complexity,
      const std::shared_ptr<SearchNode>& goal_node)
  : solved{true},
    time_complexity{time_complexity},
    space_complexity{space_complexity} {
  this->build_solution_steps(goal_node);
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

bool Solution::is_solved () const {
  return this->solved;
}

bool Solution::not_solved () const {
  return (! this->is_solved());
}

size_t Solution::get_num_steps () const {
  return this->steps.size();
}

unsigned int Solution::get_total_cost () const {
  if (this->steps.empty())
    return 0;
  return this->steps.back()->get_path_cost();
}

size_t Solution::get_time_complexity () const {
  return this->time_complexity;
}

size_t Solution::get_space_complexity () const {
  return this->space_complexity;
}

void Solution::for_each_step (const std::function<void(std::shared_ptr<SearchNode>)>& act_on_step) const {
  for (const auto& step : this->steps)
    act_on_step(step);
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

void Solution::build_solution_steps (const std::shared_ptr<SearchNode>& node) {
  for (std::optional<std::shared_ptr<SearchNode>> sn = node; sn.has_value(); sn = sn.value()->get_parent())
    this->steps.push_front(sn.value());
}


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
#include <iostream>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "MoveDir.hpp"
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

Solution::Solution (size_t time_complexity, size_t space_complexity, Solution solution)
  : solved{true},
    steps{solution.steps},
    time_complexity{time_complexity},
    space_complexity{space_complexity}
{ }

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

void Solution::print () const {
  if (this->is_solved()) {
    this->print_solution_steps();
    this->print_solution_stats();
  } else {
    this->print_null_solution();
  }
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

void Solution::build_solution_steps (const std::shared_ptr<SearchNode>& node) {
  for (std::optional<std::shared_ptr<SearchNode>> sn = node; sn.has_value(); sn = sn.value()->get_parent())
    this->steps.push_front(sn.value());
}

void Solution::print_null_solution () const {
  std::cout << std::endl << "No solution found." << std::endl;
}

void Solution::print_solution_steps () const {
  auto print_node = [this] (auto node) {
    const Board board{ node->get_board() };
    std::cout << std::endl;
    std::cout << static_cast<int>(board.get_square_val(0)) << " "
              << static_cast<int>(board.get_square_val(1)) << " "
              << static_cast<int>(board.get_square_val(2)) << "   ";
    this->print_node_depth(node);
    std::cout << static_cast<int>(board.get_square_val(3)) << " "
              << static_cast<int>(board.get_square_val(4)) << " "
              << static_cast<int>(board.get_square_val(5)) << "   ";
    this->print_node_move_direction(node);
    std::cout << static_cast<int>(board.get_square_val(6)) << " "
              << static_cast<int>(board.get_square_val(7)) << " "
              << static_cast<int>(board.get_square_val(8)) << "   ";
    this->print_node_cost(node);
  };
  this->for_each_step(print_node);
}

void Solution::print_node_depth (const std::shared_ptr<SearchNode>& node) const {
  std::cout << "depth:     ";
  if (node->get_depth() != 0)
    std::cout << node->get_depth();
  std::cout << std::endl;
}

void Solution::print_node_move_direction (const std::shared_ptr<SearchNode>& node) const {
  std::cout << "direction: ";
  if (node->get_move_dir().has_value())
    std::cout << node->get_move_dir().value();
  std::cout << std::endl;
}

void Solution::print_node_cost (const std::shared_ptr<SearchNode>& node) const {
  std::cout << "cost:      ";
  if (node->get_move_cost() > 0)
    std::cout << node->get_move_cost();
  std::cout << std::endl;
}

void Solution::print_solution_stats () const {
  std::cout << std::endl;
  std::cout << "Solution Depth (Num Steps): " << this->get_num_steps() << std::endl;
  std::cout << "Solution Path Cost:         " << this->get_total_cost() << std::endl;
  std::cout << "Solution Time Complexity:   " << this->get_time_complexity() << std::endl;
  std::cout << "Solution Space Complexity:  " << this->get_space_complexity() << std::endl;
}


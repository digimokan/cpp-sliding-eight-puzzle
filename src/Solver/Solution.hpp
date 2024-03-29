/*******************************************************************************
module:   Solution
author:   digimokan
date:     17 JAN 2019
purpose:  holds solution steps/info for a solved eight-puzzle
*******************************************************************************/

#ifndef SOLUTION_HPP
#define SOLUTION_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <deque>
#include <functional>
#include <memory>

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;
class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class Solution {

public:

  // constructors
  Solution () = delete;
  Solution (size_t time_complexity, size_t space_complexity);
  Solution (size_t time_complexity, size_t space_complexity, const std::shared_ptr<SearchNode>& goal_node);
  Solution (size_t time_complexity, size_t space_complexity, Solution solution);

  // destructor
  ~Solution () = default;

  // operators
  Solution (const Solution& in) = default;
  Solution& operator= (const Solution& rh) = delete;
  Solution (Solution&& in) = default;
  Solution& operator= (Solution&& rh) = delete;

  // specialized methods
  bool is_solved () const;
  bool not_solved () const;
  size_t get_num_steps () const;
  unsigned int get_total_cost () const;
  size_t get_time_complexity () const;
  size_t get_space_complexity () const;
  void for_each_step (const std::function<void(std::shared_ptr<SearchNode>)>&) const;
  void print () const;

private:

  // fields
  const bool solved;
  std::deque<std::shared_ptr<SearchNode>> steps;
  const size_t time_complexity;
  const size_t space_complexity;

  // helper methods
  void build_solution_steps (const std::shared_ptr<SearchNode>& goal_node);
  void print_null_solution () const;
  void print_solution_steps () const;
  void print_solution_stats () const;
  void print_node_depth (const std::shared_ptr<SearchNode>& node) const;
  void print_node_move_direction (const std::shared_ptr<SearchNode>& node) const;
  void print_node_cost (const std::shared_ptr<SearchNode>& node) const;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLUTION_HPP


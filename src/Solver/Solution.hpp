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
  Solution (size_t time_complexity, size_t space_complexity, const std::shared_ptr<SearchNode>& goal_node);

  // destructor
  ~Solution () = default;

  // operators
  Solution (const Solution& in) = default;
  Solution& operator= (const Solution& rh) = delete;
  Solution (Solution&& in) = default;
  Solution& operator= (Solution&& rh) = delete;

  // specialized methods
  unsigned int get_total_path_cost () const;
  size_t get_time_complexity () const;
  size_t get_space_complexity () const;
  void for_each_step (const std::function<void(std::shared_ptr<SearchNode>)>&) const;

private:

  // fields
  std::deque<std::shared_ptr<SearchNode>> steps;
  const size_t time_complexity;
  const size_t space_complexity;

  // helper methods
  void build_solution_steps (const std::shared_ptr<SearchNode>& goal_node);

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SOLUTION_HPP


/*******************************************************************************
module:   FrontierQueueDFS
author:   digimokan
date:     21 JAN 2019
purpose:  simple DFS LIFO queue with no est-goal-cost strategy
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <cassert>
#include <functional>
#include <list>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueDFS.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* PUBLIC BASE / DERIVED METHODS
*******************************************************************************/

bool FrontierQueueDFS::is_empty () const {
  return this->fq.empty();
}

bool FrontierQueueDFS::contains (const Board& board) const {
  auto find_board = [board] (auto node) { return (node->get_board() == board); };
  return ( std::find_if(this->fq.begin(), this->fq.end(), find_board) != this->fq.end() );
}

size_t FrontierQueueDFS::get_current_queue_size () const {
  return this->fq.size();
}

/*******************************************************************************
* TEMPLATE METHODS
*******************************************************************************/

void FrontierQueueDFS::push_logic (std::shared_ptr<SearchNode> node) {
  this->fq.push_back(node);
}

std::shared_ptr<SearchNode> FrontierQueueDFS::pop_logic () {
  assert(this->not_empty());
  auto node{ this->fq.back() };
  this->fq.pop_back();
  return node;
}


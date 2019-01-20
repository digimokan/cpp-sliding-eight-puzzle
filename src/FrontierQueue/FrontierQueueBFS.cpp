/*******************************************************************************
module:   FrontierQueueBFS
author:   digimokan
date:     17 JAN 2019
purpose:  simple BFS FIFO queue with no est-goal-cost strategy
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

#include "FrontierQueueBFS.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* PUBLIC BASE / DERIVED METHODS
*******************************************************************************/

bool FrontierQueueBFS::is_empty () const {
  return this->fq.empty();
}

bool FrontierQueueBFS::contains (const Board& board) const {
  auto find_board = [board] (auto node) { return (node->get_board() == board); };
  return ( std::find_if(this->fq.begin(), this->fq.end(), find_board) != this->fq.end() );
}

size_t FrontierQueueBFS::get_current_queue_size () const {
  return this->fq.size();
}

/*******************************************************************************
* TEMPLATE METHODS
*******************************************************************************/

void FrontierQueueBFS::push_logic (std::shared_ptr<SearchNode> node) {
  this->fq.push_back(node);
}

std::shared_ptr<SearchNode> FrontierQueueBFS::pop_logic () {
  assert(this->not_empty());
  auto node{ this->fq.front() };
  this->fq.pop_front();
  return node;
}


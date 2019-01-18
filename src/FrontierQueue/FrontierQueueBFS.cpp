/*******************************************************************************
module:   FrontierQueueBFS
author:   digimokan
date:     17 JAN 2019
purpose:  simple BFS FIFO queue with no est-goal-cost strategy
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cassert>
#include <memory>
#include <queue>

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

size_t FrontierQueueBFS::get_current_queue_size () const {
  return this->fq.size();
}

/*******************************************************************************
* TEMPLATE METHODS
*******************************************************************************/

void FrontierQueueBFS::push_logic (std::shared_ptr<SearchNode> node) {
  this->fq.push(node);
}

std::shared_ptr<SearchNode> FrontierQueueBFS::pop_logic () {
  assert(this->not_empty());
  auto node{ this->fq.front() };
  this->fq.pop();
  return node;
}


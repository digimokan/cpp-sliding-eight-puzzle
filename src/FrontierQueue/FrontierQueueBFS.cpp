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
#include <list>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBFS.hpp"
#include "SearchNode.hpp"

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


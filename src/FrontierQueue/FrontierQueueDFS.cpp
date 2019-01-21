/*******************************************************************************
module:   FrontierQueueDFS
author:   digimokan
date:     21 JAN 2019
purpose:  simple DFS LIFO queue with no est-goal-cost strategy
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

#include "FrontierQueueDFS.hpp"
#include "SearchNode.hpp"

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


/*******************************************************************************
module:   FrontierQueueEstCost
author:   digimokan
date:     22 JAN 2019
purpose:  priority queues based on est cost to goal (uniform, f(n), g(n), etc.)
template param:
          a type that implements EstGoalCostIface
*******************************************************************************/

#ifndef FRONTIER_QUEUE_EST_COST_HXX
#define FRONTIER_QUEUE_EST_COST_HXX 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cassert>
#include <memory>
#include <queue>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "SearchNode.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

#include "FrontierQueueEstCost.hpp"

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

template <typename T>
void FrontierQueueEstCost<T>::push_logic (std::shared_ptr<SearchNode> node) {
  this->fq.push(node);
}

template <typename T>
std::shared_ptr<SearchNode> FrontierQueueEstCost<T>::pop_logic () {
  assert(this->not_empty());
  auto node{ this->fq.top() };
  this->fq.pop();
  return node;
}

template <typename T>
std::shared_ptr<SearchNode> FrontierQueueEstCost<T>::peek_next_logic () const {
  return this->fq.top();
}

template <typename T>
size_t FrontierQueueEstCost<T>::get_size_logic () const {
  return this->fq.size();
}

/*******************************************************************************
* END
*******************************************************************************/

#endif // FRONTIER_QUEUE_EST_COST_HXX


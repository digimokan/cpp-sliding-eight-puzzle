/*******************************************************************************
module:   FrontierQueueBase
author:   digimokan
date:     17 JAN 2019
purpose:  base implementation for a "frontier queue" of a search graph
          --> tracks queue statistics
          --> queue type / usage implemented by FrontierQueueBase implementer
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <cstddef>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBase.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

FrontierQueueBase::FrontierQueueBase ()
  : largest_queue_size{0}, num_nodes_popped{0}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

size_t FrontierQueueBase::get_largest_queue_size () const {
  return this->largest_queue_size;
}

size_t FrontierQueueBase::get_num_nodes_popped () const {
  return this->num_nodes_popped;
}

void FrontierQueueBase::push (std::shared_ptr<SearchNode> node) {
  this->push_logic(node);
  this->largest_queue_size = std::max(this->get_current_queue_size(), this->largest_queue_size);
}

std::shared_ptr<SearchNode> FrontierQueueBase::pop () {
  auto node{ this->pop_logic() };
  this->num_nodes_popped++;
  return node;
}

bool FrontierQueueBase::not_empty () const {
  return (! this->is_empty());
}


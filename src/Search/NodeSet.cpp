/*******************************************************************************
module:   NodeSet
author:   digimokan
date:     22 JAN 2019
purpose:  a set of SearchNodes with O(1) addition, removal, and lookup
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cassert>
#include <memory>
#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "NodeSet.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

void NodeSet::add (const std::shared_ptr<SearchNode>& node) {
  this->node_set.insert(node);
}

void NodeSet::remove (const std::shared_ptr<SearchNode>& node) {
  assert(this->contains(node));
  this->node_set.erase(node);
}

bool NodeSet::contains (const std::shared_ptr<SearchNode>& node) const {
  return (this->node_set.count(node) != 0);
}

bool NodeSet::not_contains (const std::shared_ptr<SearchNode>& node) const {
  return (! this->contains(node));
}


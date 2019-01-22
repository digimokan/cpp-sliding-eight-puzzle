/*******************************************************************************
module:   NodeSet
author:   digimokan
date:     22 JAN 2019
purpose:  a set of SearchNodes with O(1) addition, removal, and lookup
*******************************************************************************/

#ifndef NODE_SET_HPP
#define NODE_SET_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <memory>
#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "SearchNode.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class NodeSet {

public:

  // constructors
  NodeSet () = default;

  // destructor
  ~NodeSet () = default;

  // operators
  NodeSet (const NodeSet& in) = delete;
  NodeSet& operator= (const NodeSet& rh) = delete;
  NodeSet (NodeSet&& in) = delete;
  NodeSet& operator= (NodeSet&& rh) = delete;

  // specialized methods
  void add (const std::shared_ptr<SearchNode>&);
  void remove (const std::shared_ptr<SearchNode>&);
  bool contains (const std::shared_ptr<SearchNode>&) const;
  bool not_contains (const std::shared_ptr<SearchNode>&) const;

private:

  // fields
  std::unordered_set<std::shared_ptr<SearchNode>> node_set;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // NODE_SET_HPP


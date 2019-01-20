/*******************************************************************************
module:   SearchGraph
author:   digimokan
date:     18 JAN 2019
purpose:  graph of SearchNodes representing search space
*******************************************************************************/

#ifndef SEARCH_GRAPH_HPP
#define SEARCH_GRAPH_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <functional>
#include <memory>
#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "MoveGenerator.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Move;
class MoveCostIface;
class SearchNode;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class SearchGraph {

public:

  // constructors
  SearchGraph () = delete;
  explicit SearchGraph (std::shared_ptr<SearchNode> root, std::shared_ptr<MoveCostIface> move_cost);

  // destructor
  ~SearchGraph () = default;

  // operators
  SearchGraph (const SearchGraph& in) = delete;
  SearchGraph& operator= (const SearchGraph& rh) = delete;
  SearchGraph (SearchGraph&& in) = delete;
  SearchGraph& operator= (SearchGraph&& rh) = delete;

  // specialized methods
  void expand (const std::shared_ptr<SearchNode>& node, const std::function<void(std::shared_ptr<SearchNode>)>& act_on_expanded);
  size_t get_max_depth () const;

private:

  // helper methods
  std::shared_ptr<SearchNode> create_child (const Move& move, const std::shared_ptr<SearchNode>& parent);

  // fields
  std::shared_ptr<SearchNode> root;
  std::unique_ptr<MoveGenerator> move_gen;
  std::unordered_set<std::shared_ptr<SearchNode>> node_set;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SEARCH_GRAPH_HPP


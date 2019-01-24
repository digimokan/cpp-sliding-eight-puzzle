/*******************************************************************************
module:   SearchGraph
author:   digimokan
date:     18 JAN 2019
purpose:  graph of SearchNodes representing search space
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <functional>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Move.hpp"
#include "MoveCostIface.hpp"
#include "MoveGenerator.hpp"
#include "SearchGraph.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

SearchGraph::SearchGraph (std::shared_ptr<SearchNode> root,
      std::shared_ptr<MoveCostIface> move_cost)
  : root{std::move(root)},
    move_gen{std::make_unique<MoveGenerator>(move_cost)} {
  this->node_set.insert(root);
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::shared_ptr<SearchNode> SearchGraph::get_root () const {
  return this->root;
}

void SearchGraph::expand (const std::shared_ptr<SearchNode>& node,
    const std::function<void(std::shared_ptr<SearchNode>)>& act_on_expanded) {
  for (const auto& move : this->move_gen->generate_moves(node->get_board()))
    act_on_expanded(this->create_child(move, node));
}

size_t SearchGraph::get_max_depth () const {
  return this->root->get_height();
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

std::shared_ptr<SearchNode> SearchGraph::create_child (const Move& move,
    const std::shared_ptr<SearchNode>& parent) {
  auto child{ std::make_shared<SearchNode>(move, parent) };
  this->node_set.insert(child);
  parent->add_child(child);
  return child;
}


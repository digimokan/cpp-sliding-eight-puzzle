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
#include <list>
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
    move_gen{std::make_unique<MoveGenerator>(move_cost)}
{ }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

void SearchGraph::expand (const std::shared_ptr<SearchNode>& node,
    const std::function<void(std::shared_ptr<SearchNode>)>& act_on_expanded) {
  std::list<std::shared_ptr<SearchNode>> children;
  for (const auto& move : this->move_gen->generate_moves(node->get_board())) {
    auto child{ this->create_child(move, node) };
    children.push_back(child);
    act_on_expanded(child);
  }
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
  parent->add_child(child);
  return child;
}


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
#include <cassert>
#include <cstddef>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "BoardMap.hpp"
#include "FrontierQueueBase.hpp"
#include "NodeSet.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

FrontierQueueBase::FrontierQueueBase ()
  : current_queue_size{0}, largest_queue_size{0}, num_nodes_popped{0}
{ }

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

void FrontierQueueBase::push (std::shared_ptr<SearchNode> node) {
  this->push_logic(node);
  this->sync_node_addition(node);
}

std::shared_ptr<SearchNode> FrontierQueueBase::pop () {
  assert(this->not_empty());
  auto node{ this->pop_logic() };
  this->sync_node_removal(node);
  this->num_nodes_popped++;
  return node;
}

bool FrontierQueueBase::contains (const Board& board) const {
  return (this->board_node_lookup.contains(board));
}

bool FrontierQueueBase::not_contains (const Board& board) const {
  return (! this->contains(board));
}

std::optional<std::shared_ptr<SearchNode>> FrontierQueueBase::get_node (const Board& board) const {
  if (this->board_node_lookup.contains(board))
    return this->board_node_lookup.get_node(board);
  return std::nullopt;
}

void FrontierQueueBase::remove_node (std::shared_ptr<SearchNode> node) {
  this->sync_node_removal(node);
}

bool FrontierQueueBase::is_empty () const {
  return (this->current_queue_size == 0);
}

bool FrontierQueueBase::not_empty () const {
  return (! this->is_empty());
}

size_t FrontierQueueBase::get_current_queue_size () const {
  return this->current_queue_size;
}

size_t FrontierQueueBase::get_largest_queue_size () const {
  return this->largest_queue_size;
}

size_t FrontierQueueBase::get_num_nodes_popped () const {
  return this->num_nodes_popped;
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

void FrontierQueueBase::sync_node_addition (const std::shared_ptr<SearchNode>& node) {
  assert(this->nodes_on_queue.not_contains(node));
  assert(this->board_node_lookup.not_contains(node->get_board()));
  this->nodes_on_queue.add(node);
  this->board_node_lookup.add(node);
  this->current_queue_size++;
  this->largest_queue_size = std::max(this->current_queue_size, this->largest_queue_size);
}

void FrontierQueueBase::sync_node_removal (const std::shared_ptr<SearchNode>& node) {
  assert(this->nodes_on_queue.contains(node));
  assert(this->board_node_lookup.contains(node->get_board()));
  this->nodes_on_queue.remove(node);
  this->board_node_lookup.remove(node);
  this->prune_removed_nodes();
  this->current_queue_size--;
}

void FrontierQueueBase::prune_removed_nodes () {
  while (this->get_size_logic() > 0) {
    auto next_node{ this->peek_next_logic() };
    if (this->nodes_on_queue.contains(next_node))
      break;
    this->pop_logic();
  }
}


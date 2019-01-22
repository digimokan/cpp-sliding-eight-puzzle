/*******************************************************************************
module:   FrontierQueueBfsDfsBase
author:   digimokan
date:     21 JAN 2019
purpose:  base STL-list-based queue impl common methods
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <algorithm>
#include <functional>
#include <list>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "FrontierQueueBfsDfsBase.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* PUBLIC BASE / DERIVED METHODS
*******************************************************************************/

bool FrontierQueueBfsDfsBase::is_empty () const {
  return this->fq.empty();
}

bool FrontierQueueBfsDfsBase::contains (const Board& board) const {
  auto find_board = [board] (auto node) { return (node->get_board() == board); };
  return ( std::find_if(this->fq.cbegin(), this->fq.cend(), find_board) != this->fq.cend() );
}

std::optional<std::shared_ptr<SearchNode>> FrontierQueueBfsDfsBase::get_node (const Board& board) const {
  auto find_board = [board] (auto node) { return (node->get_board() == board); };
  auto target_node{ std::find_if(this->fq.cbegin(), this->fq.cend(), find_board) };
  if (target_node == this->fq.cend())
    return std::nullopt;
  return *target_node;
}

void FrontierQueueBfsDfsBase::remove_node (std::shared_ptr<SearchNode> node) {
  this->fq.remove(node);
}

size_t FrontierQueueBfsDfsBase::get_current_queue_size () const {
  return this->fq.size();
}


/*******************************************************************************
module:   BoardMap
author:   digimokan
date:     16 JAN 2019
purpose:  a map of a Boards-->SearchNodes
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <unordered_map>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "BoardMap.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

bool BoardMap::contains (const Board& board) const {
  return (this->map.count(this->calc_hash_key(board)) != 0);
}

bool BoardMap::not_contains (const Board& board) const {
  return (! this->contains(board));
}

void BoardMap::add (std::shared_ptr<SearchNode> node) {
  this->map.insert(std::make_pair(this->calc_hash_key(node->get_board()), node));
}

std::optional<std::shared_ptr<SearchNode>> BoardMap::get_node (const Board& board) const {
  if (this->contains(board))
    return this->map.at(this->calc_hash_key(board));
  return std::nullopt;
}

void BoardMap::remove (const std::shared_ptr<SearchNode>& node) {
  this->map.erase(this->calc_hash_key(node->get_board()));
}

size_t BoardMap::get_size () const {
  return this->map.size();
}

unsigned int BoardMap::get_path_cost (const Board& board) const {
  return this->map.at(this->calc_hash_key(board))->get_path_cost();
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

uint64_t BoardMap::calc_hash_key (const Board& board) const {
  uint64_t key{ 0 };
  for (size_t i = 0, mult = 1; i < board.get_num_board_squares(); i++, mult *= 10)
    key += (board.get_square_val(i) * mult);
  return key;
}


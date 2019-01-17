/*******************************************************************************
module:   BoardHistory
author:   digimokan
date:     16 JAN 2019
purpose:  a history of a boards that have been visited/processed during search
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstddef>
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <utility>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "BoardHistory.hpp"
#include "SearchNode.hpp"

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

bool BoardHistory::is_in_history (const Board& board) const {
  return (this->history.count(this->calc_hash_key(board)) != 0);
}

bool BoardHistory::not_in_history (const Board& board) const {
  return (! this->is_in_history(board));
}

void BoardHistory::add_to_history (Board board, std::shared_ptr<SearchNode> node) {
  this->history.insert(std::make_pair(this->calc_hash_key(board), node));
}

unsigned int BoardHistory::get_path_cost (const Board& board) const {
  return this->history.at(this->calc_hash_key(board))->get_path_cost();
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

uint64_t BoardHistory::calc_hash_key (const Board& board) const {
  uint64_t key{ 0 };
  for (size_t i = 0, mult = 1; i < board.get_num_board_squares(); i++, mult *= 10)
    key += (board.get_square_val(i) * mult);
  return key;
}


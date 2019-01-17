/*******************************************************************************
module:   BoardHistory
author:   digimokan
date:     16 JAN 2019
purpose:  a history of a boards that have been visited/processed during search
*******************************************************************************/

#ifndef BOARD_HISTORY_HPP
#define BOARD_HISTORY_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstdint>
#include <memory>
#include <unordered_map>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "SearchNode.hpp"

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

class Board;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class BoardHistory {

public:

  // constructors
  BoardHistory () = default;

  // destructor
  ~BoardHistory () = default;

  // operators
  BoardHistory (const BoardHistory& in) = delete;
  BoardHistory& operator= (const BoardHistory& rh) = delete;
  BoardHistory (BoardHistory&& in) = delete;
  BoardHistory& operator= (BoardHistory&& rh) = delete;

  // specialized methods
  bool is_in_history (const Board&) const;
  bool not_in_history (const Board&) const;
  void add_to_history (Board, std::shared_ptr<SearchNode>);
  unsigned int get_path_cost (const Board&) const;

private:

  // fields
  std::unordered_map<uint64_t, std::shared_ptr<SearchNode>> history;

  // helper methods
  uint64_t calc_hash_key (const Board&) const;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // BOARD_HISTORY_HPP


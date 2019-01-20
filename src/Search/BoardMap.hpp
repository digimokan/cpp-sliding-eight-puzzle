/*******************************************************************************
module:   BoardMap
author:   digimokan
date:     16 JAN 2019
purpose:  a map of a Boards-->SearchNodes
*******************************************************************************/

#ifndef BOARD_MAP_HPP
#define BOARD_MAP_HPP 1

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

class BoardMap {

public:

  // constructors
  BoardMap () = default;

  // destructor
  ~BoardMap () = default;

  // operators
  BoardMap (const BoardMap& in) = delete;
  BoardMap& operator= (const BoardMap& rh) = delete;
  BoardMap (BoardMap&& in) = delete;
  BoardMap& operator= (BoardMap&& rh) = delete;

  // specialized methods
  bool contains (const Board&) const;
  bool not_contains (const Board&) const;
  void add (std::shared_ptr<SearchNode>);
  void remove (const std::shared_ptr<SearchNode>&);
  size_t get_size () const;
  unsigned int get_path_cost (const Board&) const;

private:

  // fields
  std::unordered_map<uint64_t, std::shared_ptr<SearchNode>> map;

  // helper methods
  uint64_t calc_hash_key (const Board&) const;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // BOARD_MAP_HPP


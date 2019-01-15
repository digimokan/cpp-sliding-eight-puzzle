/*******************************************************************************
module:   MoveCostSqVal
author:   digimokan
date:     13 JAN 2019
purpose:  calc move cost based on val of square to swap with empty square
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstdint>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "MoveCostSqVal.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int MoveCostSqVal::calc_cost (const Board& board, MoveDir move_dir) {
  size_t swap_pos{ board.get_swap_pos(move_dir) };
  uint8_t square_val{ board.get_square_val(swap_pos) };
  return static_cast<unsigned int>(square_val);
}


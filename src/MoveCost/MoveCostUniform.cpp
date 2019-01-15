/*******************************************************************************
module:   MoveCostUniform
author:   digimokan
date:     13 JAN 2019
purpose:  uniform move cost (all moves cost 1, regardless of square values)
*******************************************************************************/

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "CompilerUtils.hpp"
#include "MoveCostUniform.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int MoveCostUniform::calc_cost (const Board& board, MoveDir move_dir) {
  MARK_AS_USED(board, move_dir);
  return 1u;
}


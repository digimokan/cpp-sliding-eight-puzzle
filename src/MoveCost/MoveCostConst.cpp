/*******************************************************************************
module:   MoveCostConst
author:   digimokan
date:     13 JAN 2019
purpose:  constant move cost (all moves cost 1, regardless of square values)
*******************************************************************************/

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "CompilerUtils.hpp"
#include "MoveCostConst.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* BASE / DERIVED METHODS
*******************************************************************************/

unsigned int MoveCostConst::calc_cost (const Board& board, MoveDir move_dir) {
  MARK_AS_USED(board, move_dir);
  return 1u;
}


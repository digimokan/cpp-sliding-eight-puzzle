/*******************************************************************************
module:   Move
author:   digimokan
date:     13 JAN 2019
purpose:  a new board, the empty-sq move that created it, and the move's cost
*******************************************************************************/

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "Move.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

Move::Move (Board new_board, MoveDir move_dir, unsigned int cost)
  : new_board{new_board}, move_dir{move_dir}, cost{cost} { }

/*******************************************************************************
* GET/SET METHODS
*******************************************************************************/

Board Move::get_board () const {
  return this->new_board;
}

MoveDir Move::get_move_dir () const {
  return this->move_dir;
}

unsigned int Move::get_cost () const {
  return this->cost;
}


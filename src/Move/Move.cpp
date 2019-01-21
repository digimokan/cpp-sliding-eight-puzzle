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
* OPERATORS
*******************************************************************************/

bool Move::operator== (const Move& rh) {
  bool boards_equal{ this->get_board() == rh.get_board() };
  bool move_dirs_equal{ this->get_move_dir() == rh.get_move_dir() };
  bool costs_equal{ this->get_cost() == rh.get_cost() };
  return (boards_equal && move_dirs_equal && costs_equal);
}

bool Move::operator!= (const Move& rh) {
  return (! (*this == rh));
}

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


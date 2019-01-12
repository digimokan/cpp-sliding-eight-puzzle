/*******************************************************************************
module:   Square
author:   digimokan
date:     11 JAN 2019
purpose:  a board square, which can contain SquareVal (1-8, or empty)
*******************************************************************************/

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Square.hpp"
#include "SquareVal.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

Square::Square ()
  : val{SquareVal::EMPTY} { }

Square::Square (SquareVal val)
  : val{val} { }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

SquareVal Square::get_val () const {
  return this->val;
}

void Square::set_val (SquareVal in_val) {
  this->val = in_val;
}

bool Square::is_empty () const {
  return (this->val == SquareVal::EMPTY);
}

bool Square::non_empty () const {
  return (! this->is_empty());
}


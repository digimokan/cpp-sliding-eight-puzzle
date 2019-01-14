/*******************************************************************************
module:   Square
author:   digimokan
date:     11 JAN 2019
purpose:  a board square, which can contain val 1-8, or 0 for empty
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cassert>
#include <cstdint>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Square.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

Square::Square ()
  : val{0} { }

Square::Square (uint8_t val)
    : val{val} {
  assert(this->val <= 8);
}

/*******************************************************************************
* OPERATORS
*******************************************************************************/

bool Square::operator== (const Square& rh) {
  return (this->val == rh.val);
}

bool Square::operator!= (const Square& rh) {
  return (! (*this == rh));
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

uint8_t Square::get_val () const {
  return this->val;
}

void Square::set_val (uint8_t in_val) {
  this->val = in_val;
  assert(this->val <= 8);
}

bool Square::is_empty () const {
  return (this->val == 0);
}

bool Square::non_empty () const {
  return (! this->is_empty());
}


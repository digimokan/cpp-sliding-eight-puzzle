/*******************************************************************************
module:   Square
author:   digimokan
date:     11 JAN 2019
purpose:  a board square, which can contain val 1-8, or 0 for empty
*******************************************************************************/

#ifndef SQUARE_HPP
#define SQUARE_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <cstdint>

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class Square {

public:

  // constructors
  Square ();
  explicit Square (uint8_t);

  // destructor
  ~Square () = default;

  // operators
  Square (const Square& in) = default;
  Square& operator= (const Square& rh) = default;
  Square (Square&& in) = default;
  Square& operator= (Square&& rh) = default;

  // specialized methods
  uint8_t get_val () const;
  void set_val (uint8_t);
  bool is_empty () const;
  bool non_empty () const;

private:

  // fields
  uint8_t val;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SQUARE_HPP


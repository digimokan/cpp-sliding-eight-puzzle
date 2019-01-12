/*******************************************************************************
module:   Square
author:   digimokan
date:     11 JAN 2019
purpose:  a board square, which can contain SquareVal (1-8, or empty)
*******************************************************************************/

#ifndef SQUARE_HPP
#define SQUARE_HPP 1

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

enum class SquareVal;

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class Square {

public:

  // constructors
  Square ();
  explicit Square (SquareVal);

  // destructor
  ~Square () = default;

  // operators
  Square (const Square& in) = default;
  Square& operator= (const Square& rh) = default;
  Square (Square&& in) = default;
  Square& operator= (Square&& rh) = default;

  // specialized methods
  SquareVal get_val () const;
  void set_val (SquareVal);
  bool is_empty () const;
  bool non_empty () const;

private:

  // fields
  SquareVal val;

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // SQUARE_HPP


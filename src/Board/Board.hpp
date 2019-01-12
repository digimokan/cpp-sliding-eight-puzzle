/*******************************************************************************
module:   Board
author:   digimokan
date:     11 JAN 2019
purpose:  a 3x3 eight-puzzle board of Square objects
*******************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <array>
#include <string>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Square.hpp"

/*******************************************************************************
* INTERFACE
*******************************************************************************/

class Board {

public:

  // types
  enum class InitStatus {
    SUCCESS,
    ERROR_INPUT_STR_TOO_SHORT,
    ERROR_MISSING_EMPTY_SQUARE,
    ERROR_MISSING_VAL_ONE,
    ERROR_MISSING_VAL_TWO,
    ERROR_MISSING_VAL_THREE,
    ERROR_MISSING_VAL_FOUR,
    ERROR_MISSING_VAL_FIVE,
    ERROR_MISSING_VAL_SIX,
    ERROR_MISSING_VAL_SEVEN,
    ERROR_MISSING_VAL_EIGHT,
    ERROR_UNKNOWN_ILLEGAL_BOARD_CREATED
  };

  // constructors
  Board ();

  // destructor
  ~Board () = default;

  // operators
  Board (const Board& in) = default;
  Board& operator= (const Board& rh) = default;
  Board (Board&& in) = default;
  Board& operator= (Board&& rh) = default;

  // specialized methods
  InitStatus initialize (const std::string&);
  bool is_empty_board () const;
  bool not_empty_board () const;
  bool is_legal_board () const;
  bool not_legal_board () const;
  bool is_winning_board () const;
  Square& get_empty_square () const;

private:

  // fields
  std::array<Square, 9> squares;

  // helper methods
  SquareVal map_square_val (const char&) const;
  InitStatus check_input_str (const std::string&) const;
  InitStatus init_board_from_input_str (const std::string&);

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // BOARD_HPP


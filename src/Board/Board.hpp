/*******************************************************************************
module:   Board
author:   digimokan
date:     11 JAN 2019
purpose:  a 3x3 eight-puzzle board of Square objects
          board positions as follows:
                0 1 2
                3 4 5
                6 7 8
*******************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP 1

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <array>
#include <cstdint>
#include <iostream>
#include <string>

/*******************************************************************************
* FORWARD DECLARES
*******************************************************************************/

enum class MoveDir;

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
  explicit Board (const std::string&);

  // destructor
  ~Board () = default;

  // operators
  Board (const Board& in) = default;
  Board& operator= (const Board& rh) = default;
  Board (Board&& in) = default;
  Board& operator= (Board&& rh) = default;
  bool operator== (const Board& rh);
  bool operator!= (const Board& rh);

  // specialized methods
  constexpr size_t get_num_board_squares () const { return this->squares.size(); }
  InitStatus initialize (const std::string&);
  bool is_empty_board () const;
  bool not_empty_board () const;
  bool is_legal_board () const;
  bool not_legal_board () const;
  size_t get_empty_square_pos () const;
  uint8_t get_square_val (size_t board_pos) const;
  size_t get_swap_pos (MoveDir) const;
  void swap_squares (size_t pos_one, size_t pos_two);

  // friend class methods
  friend std::ostream& operator<< (std::ostream&, const Board&);

private:

  // fields
  std::array<uint8_t, 9> squares;

  // helper methods
  InitStatus check_input_str (const std::string&) const;
  InitStatus init_board_from_input_str (const std::string&);

};

/*******************************************************************************
* END
*******************************************************************************/

#endif // BOARD_HPP


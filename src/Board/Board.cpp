/*******************************************************************************
module:   Board
author:   digimokan
date:     11 JAN 2019
purpose:  a 3x3 eight-puzzle board of Square objects
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <array>
#include <cassert>
#include <cstddef>
#include <string>
#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "Square.hpp"
#include "SquareVal.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

Board::Board ()
  : squares{} { }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

Board::InitStatus Board::initialize (const std::string& input_str) {
  Board::InitStatus status{ Board::InitStatus::SUCCESS };
  status = this->check_input_str(input_str);
  if (status == Board::InitStatus::SUCCESS)
    status = this->init_board_from_input_str(input_str);
  return status;
}

bool Board::is_legal_board () const {
  std::unordered_set<SquareVal> found_vals;
  for (const auto& sq : this->squares)
    found_vals.insert(sq.get_val());
  return (found_vals.size() == 9);
}

bool Board::not_legal_board () const {
  return (! this->is_legal_board());
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

Board::InitStatus Board::check_input_str (const std::string& input_str) const {
  Board::InitStatus status{ Board::InitStatus::SUCCESS };
  if (input_str.find('0') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_EMPTY_SQUARE;
  if (input_str.find('1') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_VAL_ONE;
  if (input_str.find('2') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_VAL_TWO;
  if (input_str.find('3') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_VAL_THREE;
  if (input_str.find('4') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_VAL_FOUR;
  if (input_str.find('5') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_VAL_FIVE;
  if (input_str.find('6') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_VAL_SIX;
  if (input_str.find('7') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_VAL_SEVEN;
  if (input_str.find('8') == std::string::npos)
    status = Board::InitStatus::ERROR_MISSING_VAL_EIGHT;
  if (input_str.length() != 9)
    status = Board::InitStatus::ERROR_INPUT_STR_TOO_SHORT;
  return status;
}

Board::InitStatus Board::init_board_from_input_str (const std::string& input_str) {
  Board::InitStatus status{ Board::InitStatus::SUCCESS };
  for (size_t i = 0; i < this->squares.size(); i++)
    this->squares.at(i).set_val( this->map_square_val(input_str[i]) );
  if (this->not_legal_board())
    status = Board::InitStatus::ERROR_UNKNOWN_ILLEGAL_BOARD_CREATED;
  return status;
}

SquareVal Board::map_square_val (const char& ch) const {
  SquareVal return_sq;
  switch (ch) {
    case '0':
      return_sq = SquareVal::EMPTY;
      break;
    case '1':
      return_sq = SquareVal::ONE;
      break;
    case '2':
      return_sq = SquareVal::TWO;
      break;
    case '3':
      return_sq = SquareVal::THREE;
      break;
    case '4':
      return_sq = SquareVal::FOUR;
      break;
    case '5':
      return_sq = SquareVal::FIVE;
      break;
    case '6':
      return_sq = SquareVal::SIX;
      break;
    case '7':
      return_sq = SquareVal::SEVEN;
      break;
    case '8':
      return_sq = SquareVal::EIGHT;
      break;
    default:
      assert(false);
      break;
  }
  return return_sq;
}


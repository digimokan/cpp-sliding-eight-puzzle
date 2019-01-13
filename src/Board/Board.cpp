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
#include <cstdint>
#include <string>
#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "Square.hpp"

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
  std::unordered_set<uint8_t> found_vals;
  for (const auto& sq : this->squares)
    found_vals.insert(sq.get_val());
  return (found_vals.size() == 9);
}

bool Board::not_legal_board () const {
  return (! this->is_legal_board());
}

bool Board::is_empty_board () const {
  bool board_empty{ true };
  for (const auto& sq : this->squares) {
    if (sq.non_empty())
      board_empty = false;
  }
  return board_empty;
}

bool Board::not_empty_board () const {
  return (! this->is_empty_board());
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
    this->squares.at(i).set_val(stoi(input_str.substr(i, 1)));
  if (this->not_legal_board())
    status = Board::InitStatus::ERROR_UNKNOWN_ILLEGAL_BOARD_CREATED;
  return status;
}


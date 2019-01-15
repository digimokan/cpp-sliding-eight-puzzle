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

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "MoveDir.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

Board::Board ()
  : squares{} { }

Board::Board (const std::string& input_str)
    : Board{} {
  this->initialize(input_str);
}

/*******************************************************************************
* OPERATORS
*******************************************************************************/

bool Board::operator== (const Board& rh) {
  for (size_t i = 0; i < this->squares.size(); i++) {
    if (this->squares.at(i) != rh.squares.at(i))
      return false;
  }
  return true;
}

bool Board::operator!= (const Board& rh) {
  return (! (*this == rh));
}

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
    found_vals.insert(sq);
  return (found_vals.size() == 9);
}

bool Board::not_legal_board () const {
  return (! this->is_legal_board());
}

bool Board::is_empty_board () const {
  bool board_empty{ true };
  for (const auto& sq : this->squares) {
    if (sq != 0)
      board_empty = false;
  }
  return board_empty;
}

bool Board::not_empty_board () const {
  return (! this->is_empty_board());
}

size_t Board::get_empty_square_pos () const {
  size_t empty_sq{ this->squares.size() };
  for (size_t i = 0; i < this->squares.size(); i++) {
    if (this->squares.at(i) == 0) {
      empty_sq = i;
      break;
    }
  }
  assert(empty_sq != this->squares.size());
  return empty_sq;
}

uint8_t Board::get_square_val (size_t board_pos) const {
  assert(board_pos < this->squares.size());
  return this->squares.at(board_pos);
}

size_t Board::get_swap_pos (MoveDir move_dir) const {
  size_t empty_sq_pos{ this->get_empty_square_pos() };
  switch (move_dir) {
  case MoveDir::UP:
    assert(empty_sq_pos > 2);
    return (empty_sq_pos - 3);
    break;
  case MoveDir::DOWN:
    assert(empty_sq_pos < 6);
    return (empty_sq_pos + 3);
    break;
  case MoveDir::LEFT:
    assert((empty_sq_pos % 3) != 0);
    return (empty_sq_pos - 1);
    break;
  case MoveDir::RIGHT:
    assert((empty_sq_pos % 3) != 2);
    return (empty_sq_pos + 1);
    break;
  default:
    assert(false);
    break;
  }
}

void Board::swap_squares (size_t pos_one, size_t pos_two) {
  assert(pos_one < this->squares.size());
  assert(pos_two < this->squares.size());
  uint8_t temp{ this->squares.at(pos_one) };
  this->squares.at(pos_one) = this->squares.at(pos_two);
  this->squares.at(pos_two) = temp;
}

/*******************************************************************************
* FRIEND CLASS METHODS
*******************************************************************************/

std::ostream& operator<< (std::ostream& os, const Board& board) {
  for (const auto& sq : board.squares)
    os << static_cast<unsigned int>(sq);
  return os;
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
    this->squares.at(i) = stoi(input_str.substr(i, 1));
  if (this->not_legal_board())
    status = Board::InitStatus::ERROR_UNKNOWN_ILLEGAL_BOARD_CREATED;
  return status;
}


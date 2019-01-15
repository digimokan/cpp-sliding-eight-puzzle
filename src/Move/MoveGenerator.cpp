/*******************************************************************************
module:   MoveGenerator
author:   digimokan
date:     13 JAN 2019
purpose:  given board and move-cost-function, generate list of possible moves
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <list>
#include <memory>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "Board.hpp"
#include "Move.hpp"
#include "MoveCostIface.hpp"
#include "MoveDir.hpp"
#include "MoveGenerator.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

MoveGenerator::MoveGenerator (std::shared_ptr<MoveCostIface> move_cost)
  : move_cost{std::move(move_cost)} { }

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::list<Move> MoveGenerator::generate_moves (const Board& board) {
  std::list<Move> moves{};
  for (const auto& dir : this->generate_move_dirs(board)) {
    Board new_board{ board };
    new_board.swap_squares(new_board.get_empty_square_pos(), new_board.get_swap_pos(dir));
    moves.emplace_back(new_board, dir, this->move_cost->calc_cost(board, dir));
  }
  return moves;
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

std::list<MoveDir> MoveGenerator::generate_move_dirs (const Board& board) {
  size_t empty_sq_pos{ board.get_empty_square_pos() };
  std::list<MoveDir> move_dirs{};
  if (empty_sq_pos > 2)
    move_dirs.emplace_back(MoveDir::UP);
  if (empty_sq_pos < 6)
    move_dirs.emplace_back(MoveDir::DOWN);
  if ((empty_sq_pos % 3) != 0)
    move_dirs.emplace_back(MoveDir::LEFT);
  if ((empty_sq_pos % 3) != 2)
    move_dirs.emplace_back(MoveDir::RIGHT);
  return move_dirs;
}

